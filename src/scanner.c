// Adapted from
// https://github.com/zealot128/tree-sitter-pug/blob/master/src/scanner.c

#include <assert.h>
#include <stdint.h>

#include "tree_sitter/parser.h"

enum TokenType {
  NEWLINE,
  INDENT,
  DEDENT,
  RUBY_ATTRIBUTE_START,
  RUBY_ATTRIBUTE_CONTENT,
};
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define VEC_RESIZE(vec, _cap)                                                  \
  void *tmp = realloc((vec).data, (_cap) * sizeof((vec).data[0]));             \
  assert(tmp != NULL);                                                         \
  (vec).data = tmp;                                                            \
  (vec).cap = (_cap);

#define VEC_GROW(vec, _cap)                                                    \
  if ((vec).cap < (_cap)) {                                                    \
    VEC_RESIZE((vec), (_cap));                                                 \
  }

#define VEC_PUSH(vec, el)                                                      \
  if ((vec).cap == (vec).len) {                                                \
    VEC_RESIZE((vec), MAX(16, (vec).len * 2));                                 \
  }                                                                            \
  (vec).data[(vec).len++] = (el);

#define VEC_POP(vec) (vec).len--;

#define VEC_NEW                                                                \
  { .len = 0, .cap = 0, .data = NULL }

#define VEC_BACK(vec) ((vec).data[(vec).len - 1])

#define VEC_FREE(vec)                                                          \
  {                                                                            \
    if ((vec).data != NULL)                                                    \
      free((vec).data);                                                        \
  }

#define VEC_CLEAR(vec) (vec).len = 0;

typedef struct {
  uint32_t len;
  uint32_t cap;
  uint16_t *data;
} indent_vec;

static indent_vec indent_vec_new() {
  indent_vec vec = VEC_NEW;
  vec.data = calloc(1, sizeof(uint16_t));
  vec.cap = 1;
  return vec;
}

typedef struct {
  indent_vec indents;
  uint16_t pending_indent;
  uint16_t pending_column;
  bool has_pending_indent;
  bool eof_newline_emitted;
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

unsigned tree_sitter_haml_external_scanner_serialize(void *payload,
                                                     char *buffer) {
  Scanner *scanner = (Scanner *)payload;
  size_t size = 0;

  buffer[size++] = scanner->has_pending_indent | (scanner->eof_newline_emitted << 1);
  buffer[size++] = (uint8_t)(scanner->pending_indent & 0xFF);
  buffer[size++] = (uint8_t)(scanner->pending_indent >> 8);
  buffer[size++] = (uint8_t)(scanner->pending_column & 0xFF);
  buffer[size++] = (uint8_t)(scanner->pending_column >> 8);

  // Serialize indent levels as 16-bit values (2 bytes each)
  // Skip the first element which is always 0
  uint32_t iter = 1;
  for (; iter < scanner->indents.len &&
         size + 2 <= TREE_SITTER_SERIALIZATION_BUFFER_SIZE;
       ++iter) {
    uint16_t indent = scanner->indents.data[iter];
    buffer[size++] = (uint8_t)(indent & 0xFF);        // Low byte
    buffer[size++] = (uint8_t)(indent >> 8);          // High byte
  }

  return size;
}

void tree_sitter_haml_external_scanner_deserialize(void *payload,
                                                   const char *buffer,
                                                   unsigned length) {
  Scanner *scanner = (Scanner *)payload;
  VEC_CLEAR(scanner->indents);
  VEC_PUSH(scanner->indents, 0);
  scanner->pending_indent = 0;
  scanner->pending_column = 0;
  scanner->has_pending_indent = false;
  scanner->eof_newline_emitted = false;

  // Deserialize pending indentation and 16-bit indent levels.
  if (length >= 5) {
    scanner->has_pending_indent = buffer[0] & 1;
    scanner->eof_newline_emitted = buffer[0] & 2;
    scanner->pending_indent = (uint8_t)buffer[1] |
                              ((uint16_t)(uint8_t)buffer[2] << 8);
    scanner->pending_column = (uint8_t)buffer[3] |
                              ((uint16_t)(uint8_t)buffer[4] << 8);
    for (size_t i = 5; i + 1 < length; i += 2) {
      uint16_t indent = (uint8_t)buffer[i] | ((uint16_t)(uint8_t)buffer[i + 1] << 8);
      VEC_PUSH(scanner->indents, indent);
    }
    return;
  }
}

void *tree_sitter_haml_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->indents = indent_vec_new();
  tree_sitter_haml_external_scanner_deserialize(scanner, NULL, 0);
  return scanner;
}

static bool resolve_pending_indent(Scanner *scanner, TSLexer *lexer,
                                   const bool *valid_symbols) {
  uint16_t current_indent = VEC_BACK(scanner->indents);
  if (scanner->pending_indent < current_indent && valid_symbols[DEDENT]) {
    VEC_POP(scanner->indents);
    lexer->result_symbol = DEDENT;
    return true;
  }
  if (scanner->pending_indent > current_indent && valid_symbols[INDENT]) {
    VEC_PUSH(scanner->indents, scanner->pending_indent);
    scanner->has_pending_indent = false;
    lexer->result_symbol = INDENT;
    return true;
  }
  if (scanner->pending_indent == current_indent) {
    scanner->has_pending_indent = false;
  }
  return false;
}

static bool scan_literal(TSLexer *lexer, int32_t opening, int32_t closing,
                         bool regex) {
  uint32_t depth = 1;
  bool in_character_class = false;
  advance(lexer);
  while (!lexer->eof(lexer)) {
    int32_t character = lexer->lookahead;
    advance(lexer);
    if (character == '\\') {
      if (!lexer->eof(lexer))
        advance(lexer);
      continue;
    }
    if (regex && character == '[')
      in_character_class = true;
    else if (regex && in_character_class && character == ']')
      in_character_class = false;
    else if (!in_character_class) {
      if (character == closing && --depth == 0)
        return true;
      if (opening != closing && character == opening)
        depth++;
    }
  }
  return false;
}

static bool scan_ruby_attribute(TSLexer *lexer, bool content) {
  if (!content) {
    if (lexer->lookahead != '{') {
      return false;
    }
    // Validate without consuming the opening brace, preserving local recovery.
    lexer->mark_end(lexer);
    advance(lexer);
  }

  uint32_t brace_depth = 1;
  bool consumed_content = false;
  // shortcut: literal starts use punctuation; add Ruby keyword/command context when needed.
  bool expects_value = true;

  while (!lexer->eof(lexer)) {
    int32_t character = lexer->lookahead;
    if (character == '}' && brace_depth == 1) {
      if (content) {
        lexer->mark_end(lexer);
      }
      return !content || consumed_content;
    }
    consumed_content = true;
    switch (character) {
    case '{':
      brace_depth++;
      expects_value = true;
      advance(lexer);
      break;
    case '}':
      brace_depth--;
      expects_value = false;
      advance(lexer);
      break;
    case '"':
    case '\'':
    case '`':
      if (!scan_literal(lexer, character, character, false))
        return false;
      expects_value = false;
      break;
    case '/':
      if (expects_value) {
        if (!scan_literal(lexer, '/', '/', true))
          return false;
        expects_value = false;
      } else {
        advance(lexer);
        expects_value = true;
      }
      break;
    case '%':
      advance(lexer);
      if (expects_value) {
        bool regex = lexer->lookahead == 'r';
        switch (lexer->lookahead) {
        case 'q': case 'Q': case 'w': case 'W':
        case 'i': case 'I': case 'x': case 'r': case 's':
          advance(lexer);
        }
        int32_t opening = lexer->lookahead;
        int32_t closing = opening;
        switch (opening) {
        case '(': closing = ')'; break;
        case '[': closing = ']'; break;
        case '{': closing = '}'; break;
        case '<': closing = '>'; break;
        }
        if (!scan_literal(lexer, opening, closing, regex))
          return false;
        expects_value = false;
      } else {
        expects_value = true;
      }
      break;
    case '#':
      while (!lexer->eof(lexer) && lexer->lookahead != '\n')
        advance(lexer);
      break;
    case '\\':
      advance(lexer);
      if (!lexer->eof(lexer))
        advance(lexer);
      break;
    case ' ': case '\t': case '\r': case '\n':
      advance(lexer);
      break;
    default:
      expects_value = character == ':' || character == ',' ||
                      character == '=' || character == '>' ||
                      character == '(' || character == '[' ||
                      character == '!' || character == '?' ||
                      character == '+' || character == '-' ||
                      character == '*' || character == '&' ||
                      character == '|' || character == '~' ||
                      character == '^' || character == ';';
      advance(lexer);
      break;
    }
  }
  return false;
}

bool tree_sitter_haml_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;

  // Attribute content includes its own newlines and must bypass HAML indentation.
  if (valid_symbols[RUBY_ATTRIBUTE_CONTENT] && !valid_symbols[NEWLINE]) {
    if (scan_ruby_attribute(lexer, true)) {
      lexer->result_symbol = RUBY_ATTRIBUTE_CONTENT;
      return true;
    }
    return false;
  }

  if (lexer->eof(lexer)) {
    scanner->has_pending_indent = false;
    if (valid_symbols[NEWLINE] && !scanner->eof_newline_emitted) {
      scanner->eof_newline_emitted = true;
      lexer->result_symbol = NEWLINE;
      return true;
    }
    if (valid_symbols[DEDENT] && scanner->indents.len > 1) {
      VEC_POP(scanner->indents);
      lexer->result_symbol = DEDENT;
      return true;
    }
    return false;
  }
  scanner->eof_newline_emitted = false;

  // Pending indentation only applies at the first non-whitespace character
  // of its own line. Once lexing has moved past that column, drop it.
  if (scanner->has_pending_indent &&
      lexer->get_column(lexer) != scanner->pending_column) {
    scanner->has_pending_indent = false;
  }
  if (scanner->has_pending_indent &&
      resolve_pending_indent(scanner, lexer, valid_symbols)) {
    return true;
  }

  // Handle indentation when there was no external newline, such as at the
  // start of a file or after a token that consumed its own newline.
  if (!scanner->has_pending_indent && lexer->lookahead != 0 &&
      lexer->lookahead != '\r' && lexer->lookahead != '\n' &&
      lexer->get_column(lexer) == 0) {
    uint16_t indent_length = 0;
    while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
      indent_length += lexer->lookahead == '\t' ? 8 : 1;
      skip(lexer);
    }
    if (lexer->lookahead != 0 && lexer->lookahead != '\r' &&
        lexer->lookahead != '\n') {
      scanner->pending_indent = indent_length;
      scanner->pending_column = lexer->get_column(lexer);
      scanner->has_pending_indent = true;
      if (resolve_pending_indent(scanner, lexer, valid_symbols)) {
        return true;
      }
    }
  }

  // Validation and content scanning each traverse the hash once.
  if (valid_symbols[RUBY_ATTRIBUTE_START] &&
      !valid_symbols[RUBY_ATTRIBUTE_CONTENT] &&
      scan_ruby_attribute(lexer, false)) {
    lexer->result_symbol = RUBY_ATTRIBUTE_START;
    return true;
  }

  // Consume indentation with the preceding newline so the next token starts
  // at its first non-whitespace character.
  if (lexer->lookahead == '\r' || lexer->lookahead == '\n') {
    if (!valid_symbols[NEWLINE]) {
      return false;
    }

    if (lexer->lookahead == '\r') {
      skip(lexer);
      if (lexer->lookahead != '\n') {
        return false;
      }
    }
    skip(lexer);
    scanner->has_pending_indent = false;

    uint16_t indent_length = 0;
    while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
      indent_length += lexer->lookahead == '\t' ? 8 : 1;
      skip(lexer);
    }

    if (lexer->lookahead != 0 && lexer->lookahead != '\r' &&
        lexer->lookahead != '\n') {
      scanner->pending_indent = indent_length;
      scanner->pending_column = lexer->get_column(lexer);
      scanner->has_pending_indent = true;
    }

    lexer->result_symbol = NEWLINE;
    return true;
  }

  return false;
}

void tree_sitter_haml_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  VEC_FREE(scanner->indents);
  free(scanner);
}
