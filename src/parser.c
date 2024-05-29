#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 40
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 29
#define ALIAS_COUNT 0
#define TOKEN_COUNT 18
#define EXTERNAL_TOKEN_COUNT 4
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_SLASH = 1,
  anon_sym_LPAREN = 2,
  anon_sym_SPACE = 3,
  anon_sym_RPAREN = 4,
  sym_id = 5,
  sym_name = 6,
  sym_class = 7,
  sym_attribute_name = 8,
  anon_sym_EQ = 9,
  anon_sym_SQUOTE = 10,
  aux_sym_quoted_attribute_value_token1 = 11,
  anon_sym_DQUOTE = 12,
  sym__text = 13,
  sym__newline = 14,
  sym__indent = 15,
  sym__dedent = 16,
  sym_ruby_attributes = 17,
  sym_source_file = 18,
  sym_tag = 19,
  sym_html_attributes = 20,
  sym_attributes = 21,
  sym_attribute = 22,
  sym_quoted_attribute_value = 23,
  sym_plain_text = 24,
  sym_buffered_code = 25,
  aux_sym_source_file_repeat1 = 26,
  aux_sym_tag_repeat1 = 27,
  aux_sym_html_attributes_repeat1 = 28,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SLASH] = "self_close_slash",
  [anon_sym_LPAREN] = "(",
  [anon_sym_SPACE] = " ",
  [anon_sym_RPAREN] = ")",
  [sym_id] = "id",
  [sym_name] = "name",
  [sym_class] = "class",
  [sym_attribute_name] = "attribute_name",
  [anon_sym_EQ] = "=",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_quoted_attribute_value_token1] = "attribute_value",
  [anon_sym_DQUOTE] = "\"",
  [sym__text] = "_text",
  [sym__newline] = "_newline",
  [sym__indent] = "_indent",
  [sym__dedent] = "_dedent",
  [sym_ruby_attributes] = "ruby_attributes",
  [sym_source_file] = "source_file",
  [sym_tag] = "tag",
  [sym_html_attributes] = "html_attributes",
  [sym_attributes] = "attributes",
  [sym_attribute] = "attribute",
  [sym_quoted_attribute_value] = "quoted_attribute_value",
  [sym_plain_text] = "plain_text",
  [sym_buffered_code] = "buffered_code",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_tag_repeat1] = "tag_repeat1",
  [aux_sym_html_attributes_repeat1] = "html_attributes_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_SPACE] = anon_sym_SPACE,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_id] = sym_id,
  [sym_name] = sym_name,
  [sym_class] = sym_class,
  [sym_attribute_name] = sym_attribute_name,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_quoted_attribute_value_token1] = aux_sym_quoted_attribute_value_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [sym__text] = sym__text,
  [sym__newline] = sym__newline,
  [sym__indent] = sym__indent,
  [sym__dedent] = sym__dedent,
  [sym_ruby_attributes] = sym_ruby_attributes,
  [sym_source_file] = sym_source_file,
  [sym_tag] = sym_tag,
  [sym_html_attributes] = sym_html_attributes,
  [sym_attributes] = sym_attributes,
  [sym_attribute] = sym_attribute,
  [sym_quoted_attribute_value] = sym_quoted_attribute_value,
  [sym_plain_text] = sym_plain_text,
  [sym_buffered_code] = sym_buffered_code,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_tag_repeat1] = aux_sym_tag_repeat1,
  [aux_sym_html_attributes_repeat1] = aux_sym_html_attributes_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SPACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_id] = {
    .visible = true,
    .named = true,
  },
  [sym_name] = {
    .visible = true,
    .named = true,
  },
  [sym_class] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_quoted_attribute_value_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__text] = {
    .visible = false,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym__dedent] = {
    .visible = false,
    .named = true,
  },
  [sym_ruby_attributes] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_html_attributes] = {
    .visible = true,
    .named = true,
  },
  [sym_attributes] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_quoted_attribute_value] = {
    .visible = true,
    .named = true,
  },
  [sym_plain_text] = {
    .visible = true,
    .named = true,
  },
  [sym_buffered_code] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_html_attributes_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(12);
      ADVANCE_MAP(
        '"', 25,
        '#', 5,
        '%', 8,
        '\'', 23,
        '(', 14,
        ')', 16,
        '.', 6,
        '/', 13,
        '=', 22,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('-' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0) ADVANCE(27);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == ')') ADVANCE(16);
      if (lookahead == '=') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(2);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(25);
      if (lookahead == '\'') ADVANCE(23);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('-' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == ')') ADVANCE(16);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 5:
      if (lookahead == ':' ||
          lookahead == '@') ADVANCE(21);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 6:
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 7:
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 9:
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 10:
      if (eof) ADVANCE(12);
      if (lookahead == ' ') ADVANCE(15);
      if (lookahead == '#') ADVANCE(7);
      if (lookahead == '%') ADVANCE(8);
      if (lookahead == '(') ADVANCE(14);
      if (lookahead == '.') ADVANCE(6);
      if (lookahead == '/') ADVANCE(13);
      if (lookahead == '=') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(10);
      END_STATE();
    case 11:
      if (eof) ADVANCE(12);
      if (lookahead == '#') ADVANCE(7);
      if (lookahead == '%') ADVANCE(8);
      if (lookahead == '.') ADVANCE(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == ':' ||
          lookahead == '@') ADVANCE(21);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_class);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (('-' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym__text);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(27);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__text);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(27);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 11},
  [2] = {.lex_state = 10, .external_lex_state = 2},
  [3] = {.lex_state = 10, .external_lex_state = 2},
  [4] = {.lex_state = 10, .external_lex_state = 2},
  [5] = {.lex_state = 10},
  [6] = {.lex_state = 10},
  [7] = {.lex_state = 10},
  [8] = {.lex_state = 10},
  [9] = {.lex_state = 10},
  [10] = {.lex_state = 10},
  [11] = {.lex_state = 10},
  [12] = {.lex_state = 10},
  [13] = {.lex_state = 11},
  [14] = {.lex_state = 11},
  [15] = {.lex_state = 11, .external_lex_state = 3},
  [16] = {.lex_state = 11, .external_lex_state = 3},
  [17] = {.lex_state = 11},
  [18] = {.lex_state = 4},
  [19] = {.lex_state = 11},
  [20] = {.lex_state = 11},
  [21] = {.lex_state = 11},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 11},
  [24] = {.lex_state = 4},
  [25] = {.lex_state = 11},
  [26] = {.lex_state = 4},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 3},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_id] = ACTIONS(1),
    [sym_name] = ACTIONS(1),
    [sym_class] = ACTIONS(1),
    [sym_attribute_name] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
    [sym_ruby_attributes] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(35),
    [sym_tag] = STATE(13),
    [aux_sym_source_file_repeat1] = STATE(13),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_id] = ACTIONS(5),
    [sym_name] = ACTIONS(5),
    [sym_class] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(7), 1,
      ts_builtin_sym_end,
    ACTIONS(9), 1,
      anon_sym_SLASH,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      anon_sym_SPACE,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(19), 1,
      sym_ruby_attributes,
    STATE(3), 1,
      aux_sym_tag_repeat1,
    STATE(6), 1,
      sym_attributes,
    STATE(11), 1,
      sym_html_attributes,
    STATE(20), 2,
      sym_plain_text,
      sym_buffered_code,
    ACTIONS(15), 3,
      sym_id,
      sym_name,
      sym_class,
  [37] = 11,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(13), 1,
      anon_sym_SPACE,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(19), 1,
      sym_ruby_attributes,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      anon_sym_SLASH,
    STATE(4), 1,
      aux_sym_tag_repeat1,
    STATE(5), 1,
      sym_attributes,
    STATE(11), 1,
      sym_html_attributes,
    STATE(19), 2,
      sym_plain_text,
      sym_buffered_code,
    ACTIONS(25), 3,
      sym_id,
      sym_name,
      sym_class,
  [74] = 4,
    STATE(4), 1,
      aux_sym_tag_repeat1,
    ACTIONS(27), 3,
      sym_ruby_attributes,
      ts_builtin_sym_end,
      anon_sym_SPACE,
    ACTIONS(29), 3,
      anon_sym_SLASH,
      anon_sym_LPAREN,
      anon_sym_EQ,
    ACTIONS(31), 3,
      sym_id,
      sym_name,
      sym_class,
  [93] = 6,
    ACTIONS(13), 1,
      anon_sym_SPACE,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
    ACTIONS(36), 1,
      anon_sym_SLASH,
    STATE(25), 2,
      sym_plain_text,
      sym_buffered_code,
    ACTIONS(38), 3,
      sym_id,
      sym_name,
      sym_class,
  [115] = 6,
    ACTIONS(13), 1,
      anon_sym_SPACE,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      anon_sym_SLASH,
    STATE(19), 2,
      sym_plain_text,
      sym_buffered_code,
    ACTIONS(40), 3,
      sym_id,
      sym_name,
      sym_class,
  [137] = 5,
    ACTIONS(13), 1,
      anon_sym_SPACE,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
    STATE(23), 2,
      sym_plain_text,
      sym_buffered_code,
    ACTIONS(44), 3,
      sym_id,
      sym_name,
      sym_class,
  [156] = 5,
    ACTIONS(13), 1,
      anon_sym_SPACE,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    STATE(19), 2,
      sym_plain_text,
      sym_buffered_code,
    ACTIONS(40), 3,
      sym_id,
      sym_name,
      sym_class,
  [175] = 5,
    ACTIONS(13), 1,
      anon_sym_SPACE,
    ACTIONS(17), 1,
      anon_sym_EQ,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
    STATE(25), 2,
      sym_plain_text,
      sym_buffered_code,
    ACTIONS(38), 3,
      sym_id,
      sym_name,
      sym_class,
  [194] = 2,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_SPACE,
    ACTIONS(48), 5,
      anon_sym_SLASH,
      sym_id,
      sym_name,
      sym_class,
      anon_sym_EQ,
  [206] = 2,
    ACTIONS(50), 2,
      ts_builtin_sym_end,
      anon_sym_SPACE,
    ACTIONS(52), 5,
      anon_sym_SLASH,
      sym_id,
      sym_name,
      sym_class,
      anon_sym_EQ,
  [218] = 2,
    ACTIONS(54), 2,
      ts_builtin_sym_end,
      anon_sym_SPACE,
    ACTIONS(56), 5,
      anon_sym_SLASH,
      sym_id,
      sym_name,
      sym_class,
      anon_sym_EQ,
  [230] = 3,
    ACTIONS(58), 1,
      ts_builtin_sym_end,
    STATE(14), 2,
      sym_tag,
      aux_sym_source_file_repeat1,
    ACTIONS(5), 3,
      sym_id,
      sym_name,
      sym_class,
  [243] = 3,
    ACTIONS(60), 1,
      ts_builtin_sym_end,
    STATE(14), 2,
      sym_tag,
      aux_sym_source_file_repeat1,
    ACTIONS(62), 3,
      sym_id,
      sym_name,
      sym_class,
  [256] = 2,
    ACTIONS(67), 1,
      sym__newline,
    ACTIONS(65), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [266] = 2,
    ACTIONS(71), 1,
      sym__newline,
    ACTIONS(69), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [276] = 1,
    ACTIONS(73), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [283] = 4,
    ACTIONS(75), 1,
      anon_sym_RPAREN,
    ACTIONS(77), 1,
      sym_attribute_name,
    STATE(18), 1,
      aux_sym_html_attributes_repeat1,
    STATE(27), 1,
      sym_attribute,
  [296] = 1,
    ACTIONS(34), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [303] = 1,
    ACTIONS(21), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [310] = 1,
    ACTIONS(80), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [317] = 3,
    ACTIONS(82), 1,
      anon_sym_SPACE,
    ACTIONS(86), 1,
      anon_sym_EQ,
    ACTIONS(84), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [328] = 1,
    ACTIONS(88), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [335] = 4,
    ACTIONS(90), 1,
      anon_sym_RPAREN,
    ACTIONS(92), 1,
      sym_attribute_name,
    STATE(18), 1,
      aux_sym_html_attributes_repeat1,
    STATE(27), 1,
      sym_attribute,
  [348] = 1,
    ACTIONS(42), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [355] = 4,
    ACTIONS(92), 1,
      sym_attribute_name,
    ACTIONS(94), 1,
      anon_sym_RPAREN,
    STATE(24), 1,
      aux_sym_html_attributes_repeat1,
    STATE(27), 1,
      sym_attribute,
  [368] = 2,
    ACTIONS(96), 1,
      anon_sym_SPACE,
    ACTIONS(98), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [376] = 2,
    ACTIONS(100), 1,
      anon_sym_SPACE,
    ACTIONS(102), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [384] = 2,
    ACTIONS(104), 1,
      anon_sym_SPACE,
    ACTIONS(106), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [392] = 2,
    ACTIONS(108), 1,
      anon_sym_SPACE,
    ACTIONS(110), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [400] = 3,
    ACTIONS(112), 1,
      anon_sym_SQUOTE,
    ACTIONS(114), 1,
      anon_sym_DQUOTE,
    STATE(30), 1,
      sym_quoted_attribute_value,
  [410] = 2,
    ACTIONS(116), 1,
      aux_sym_quoted_attribute_value_token1,
    ACTIONS(118), 1,
      anon_sym_DQUOTE,
  [417] = 2,
    ACTIONS(118), 1,
      anon_sym_SQUOTE,
    ACTIONS(120), 1,
      aux_sym_quoted_attribute_value_token1,
  [424] = 1,
    ACTIONS(75), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [429] = 1,
    ACTIONS(122), 1,
      ts_builtin_sym_end,
  [433] = 1,
    ACTIONS(124), 1,
      sym__text,
  [437] = 1,
    ACTIONS(126), 1,
      anon_sym_SQUOTE,
  [441] = 1,
    ACTIONS(126), 1,
      anon_sym_DQUOTE,
  [445] = 1,
    ACTIONS(128), 1,
      sym__text,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 37,
  [SMALL_STATE(4)] = 74,
  [SMALL_STATE(5)] = 93,
  [SMALL_STATE(6)] = 115,
  [SMALL_STATE(7)] = 137,
  [SMALL_STATE(8)] = 156,
  [SMALL_STATE(9)] = 175,
  [SMALL_STATE(10)] = 194,
  [SMALL_STATE(11)] = 206,
  [SMALL_STATE(12)] = 218,
  [SMALL_STATE(13)] = 230,
  [SMALL_STATE(14)] = 243,
  [SMALL_STATE(15)] = 256,
  [SMALL_STATE(16)] = 266,
  [SMALL_STATE(17)] = 276,
  [SMALL_STATE(18)] = 283,
  [SMALL_STATE(19)] = 296,
  [SMALL_STATE(20)] = 303,
  [SMALL_STATE(21)] = 310,
  [SMALL_STATE(22)] = 317,
  [SMALL_STATE(23)] = 328,
  [SMALL_STATE(24)] = 335,
  [SMALL_STATE(25)] = 348,
  [SMALL_STATE(26)] = 355,
  [SMALL_STATE(27)] = 368,
  [SMALL_STATE(28)] = 376,
  [SMALL_STATE(29)] = 384,
  [SMALL_STATE(30)] = 392,
  [SMALL_STATE(31)] = 400,
  [SMALL_STATE(32)] = 410,
  [SMALL_STATE(33)] = 417,
  [SMALL_STATE(34)] = 424,
  [SMALL_STATE(35)] = 429,
  [SMALL_STATE(36)] = 433,
  [SMALL_STATE(37)] = 437,
  [SMALL_STATE(38)] = 441,
  [SMALL_STATE(39)] = 445,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 1, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tag_repeat1, 2, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_tag_repeat1, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 3, 0, 0),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 2, 0, 0),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 4, 0, 0),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 4, 0, 0),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_html_attributes, 2, 0, 0),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_html_attributes, 2, 0, 0),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, 0, 0),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attributes, 1, 0, 0),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_html_attributes, 3, 0, 0),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_html_attributes, 3, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_buffered_code, 2, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_plain_text, 2, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_plain_text, 3, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_html_attributes_repeat1, 2, 0, 0),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_html_attributes_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_buffered_code, 3, 0, 0),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 5, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_html_attributes_repeat1, 1, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [122] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__newline = 0,
  ts_external_token__indent = 1,
  ts_external_token__dedent = 2,
  ts_external_token_ruby_attributes = 3,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__newline] = sym__newline,
  [ts_external_token__indent] = sym__indent,
  [ts_external_token__dedent] = sym__dedent,
  [ts_external_token_ruby_attributes] = sym_ruby_attributes,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__newline] = true,
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token_ruby_attributes] = true,
  },
  [2] = {
    [ts_external_token_ruby_attributes] = true,
  },
  [3] = {
    [ts_external_token__newline] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_haml_external_scanner_create(void);
void tree_sitter_haml_external_scanner_destroy(void *);
bool tree_sitter_haml_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_haml_external_scanner_serialize(void *, char *);
void tree_sitter_haml_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_haml(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_haml_external_scanner_create,
      tree_sitter_haml_external_scanner_destroy,
      tree_sitter_haml_external_scanner_scan,
      tree_sitter_haml_external_scanner_serialize,
      tree_sitter_haml_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
