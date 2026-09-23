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
  RUBY_ATTRIBUTE_NEWLINE,
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
  uint32_t ruby_attribute_newlines;
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

unsigned tree_sitter_haml_external_scanner_serialize(void *payload,
                                                     char *buffer) {
  Scanner *scanner = (Scanner *)payload;
  size_t size = 0;

  buffer[size++] = scanner->has_pending_indent;
  buffer[size++] = (uint8_t)(scanner->pending_indent & 0xFF);
  buffer[size++] = (uint8_t)(scanner->pending_indent >> 8);
  buffer[size++] = (uint8_t)(scanner->pending_column & 0xFF);
  buffer[size++] = (uint8_t)(scanner->pending_column >> 8);
  buffer[size++] = (uint8_t)(scanner->ruby_attribute_newlines & 0xFF);
  buffer[size++] = (uint8_t)((scanner->ruby_attribute_newlines >> 8) & 0xFF);
  buffer[size++] = (uint8_t)((scanner->ruby_attribute_newlines >> 16) & 0xFF);
  buffer[size++] = (uint8_t)(scanner->ruby_attribute_newlines >> 24);

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
  scanner->ruby_attribute_newlines = 0;

  // Deserialize pending indentation and 16-bit indent levels.
  if (length >= 5) {
    scanner->has_pending_indent = buffer[0];
    scanner->pending_indent = (uint8_t)buffer[1] |
                              ((uint16_t)(uint8_t)buffer[2] << 8);
    scanner->pending_column = (uint8_t)buffer[3] |
                              ((uint16_t)(uint8_t)buffer[4] << 8);
    size_t offset = 5;
    if (length >= 9) {
      scanner->ruby_attribute_newlines =
          (uint8_t)buffer[5] | ((uint32_t)(uint8_t)buffer[6] << 8) |
          ((uint32_t)(uint8_t)buffer[7] << 16) |
          ((uint32_t)(uint8_t)buffer[8] << 24);
      offset = 9;
    }
    for (size_t i = offset; i + 1 < length; i += 2) {
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

static bool scan_ruby_attribute_start(Scanner *scanner, TSLexer *lexer) {
  if (lexer->lookahead != '{') {
    return false;
  }
  lexer->mark_end(lexer);

  uint16_t brace_depth = 0;
  uint32_t newline_count = 0;
  bool in_string = false;
  char string_delimiter = 0;

  while (lexer->lookahead != 0) {
    if (lexer->lookahead == '\\') {
      advance(lexer);
      if (lexer->lookahead == '\r') {
        advance(lexer);
        if (lexer->lookahead == '\n') {
          advance(lexer);
        }
      } else if (lexer->lookahead != 0) {
        advance(lexer);
      }
      continue;
    }
    if (lexer->lookahead == '\r' || lexer->lookahead == '\n') {
      if (!in_string) {
        newline_count++;
      }
      if (lexer->lookahead == '\r') {
        advance(lexer);
        if (lexer->lookahead != '\n') {
          continue;
        }
      }
      advance(lexer);
      continue;
    }
    if (lexer->lookahead == '"' || lexer->lookahead == '\'') {
      if (!in_string) {
        in_string = true;
        string_delimiter = lexer->lookahead;
      } else if (lexer->lookahead == string_delimiter) {
        in_string = false;
      }
    } else if (!in_string && lexer->lookahead == '{') {
      brace_depth++;
    } else if (!in_string && lexer->lookahead == '}') {
      brace_depth--;
      if (brace_depth == 0) {
        scanner->ruby_attribute_newlines = newline_count;
        return true;
      }
    }
    advance(lexer);
  }
  return false;
}

static bool scan_ruby_attribute_newline(Scanner *scanner, TSLexer *lexer) {
  if (scanner->ruby_attribute_newlines == 0) {
    return false;
  }
  if (lexer->lookahead == '\r') {
    advance(lexer);
    if (lexer->lookahead != '\n') {
      return false;
    }
  }
  advance(lexer);
  while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
    advance(lexer);
  }
  scanner->ruby_attribute_newlines--;
  return true;
}

bool tree_sitter_haml_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;

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

  // Validate the outer hash once; the stored count keeps each newline scan O(1).
  if (valid_symbols[RUBY_ATTRIBUTE_START] &&
      !valid_symbols[RUBY_ATTRIBUTE_NEWLINE] &&
      scan_ruby_attribute_start(scanner, lexer)) {
    lexer->result_symbol = RUBY_ATTRIBUTE_START;
    return true;
  }

  if (valid_symbols[RUBY_ATTRIBUTE_NEWLINE] && !valid_symbols[NEWLINE] &&
      (lexer->lookahead == '\r' || lexer->lookahead == '\n')) {
    if (scan_ruby_attribute_newline(scanner, lexer)) {
      lexer->result_symbol = RUBY_ATTRIBUTE_NEWLINE;
      return true;
    }
    return false;
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
