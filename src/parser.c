#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 30
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 26
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 4
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
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
  sym__newline = 13,
  sym__indent = 14,
  sym__dedent = 15,
  sym_ruby_attributes = 16,
  sym_source_file = 17,
  sym_tag = 18,
  sym_html_attributes = 19,
  sym_attributes = 20,
  sym_attribute = 21,
  sym_quoted_attribute_value = 22,
  aux_sym_source_file_repeat1 = 23,
  aux_sym_tag_repeat1 = 24,
  aux_sym_html_attributes_repeat1 = 25,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(8);
      ADVANCE_MAP(
        '"', 20,
        '#', 5,
        '%', 6,
        '\'', 18,
        '(', 10,
        ')', 12,
        '.', 4,
        '/', 9,
        '=', 17,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(11);
      if (lookahead == '#') ADVANCE(7);
      if (lookahead == ')') ADVANCE(12);
      if (lookahead == '=') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r')) SKIP(1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(20);
      if (lookahead == '\'') ADVANCE(18);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('-' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(7);
      if (lookahead == ')') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 4:
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 6:
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 7:
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_SPACE);
      if (lookahead == ' ') ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_id);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_name);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_class);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_attribute_name);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= ':') ||
          ('@' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym_quoted_attribute_value_token1);
      if (('-' <= lookahead && lookahead <= ':') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 0, .external_lex_state = 2},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 3},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
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
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
    [sym__dedent] = ACTIONS(1),
    [sym_ruby_attributes] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(27),
    [sym_tag] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_id] = ACTIONS(5),
    [sym_name] = ACTIONS(5),
    [sym_class] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(7), 1,
      ts_builtin_sym_end,
    ACTIONS(9), 1,
      anon_sym_SLASH,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      sym_ruby_attributes,
    STATE(3), 1,
      aux_sym_tag_repeat1,
    STATE(8), 1,
      sym_html_attributes,
    STATE(10), 1,
      sym_attributes,
    ACTIONS(13), 3,
      sym_id,
      sym_name,
      sym_class,
  [27] = 8,
    ACTIONS(11), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      sym_ruby_attributes,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 1,
      anon_sym_SLASH,
    STATE(4), 1,
      aux_sym_tag_repeat1,
    STATE(8), 1,
      sym_html_attributes,
    STATE(9), 1,
      sym_attributes,
    ACTIONS(21), 3,
      sym_id,
      sym_name,
      sym_class,
  [54] = 3,
    STATE(4), 1,
      aux_sym_tag_repeat1,
    ACTIONS(25), 3,
      sym_id,
      sym_name,
      sym_class,
    ACTIONS(23), 4,
      sym_ruby_attributes,
      ts_builtin_sym_end,
      anon_sym_SLASH,
      anon_sym_LPAREN,
  [69] = 3,
    ACTIONS(28), 1,
      ts_builtin_sym_end,
    STATE(6), 2,
      sym_tag,
      aux_sym_source_file_repeat1,
    ACTIONS(5), 3,
      sym_id,
      sym_name,
      sym_class,
  [82] = 3,
    ACTIONS(30), 1,
      ts_builtin_sym_end,
    STATE(6), 2,
      sym_tag,
      aux_sym_source_file_repeat1,
    ACTIONS(32), 3,
      sym_id,
      sym_name,
      sym_class,
  [95] = 1,
    ACTIONS(35), 5,
      ts_builtin_sym_end,
      anon_sym_SLASH,
      sym_id,
      sym_name,
      sym_class,
  [103] = 1,
    ACTIONS(37), 5,
      ts_builtin_sym_end,
      anon_sym_SLASH,
      sym_id,
      sym_name,
      sym_class,
  [111] = 2,
    ACTIONS(41), 1,
      anon_sym_SLASH,
    ACTIONS(39), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [121] = 2,
    ACTIONS(19), 1,
      anon_sym_SLASH,
    ACTIONS(17), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [131] = 1,
    ACTIONS(43), 5,
      ts_builtin_sym_end,
      anon_sym_SLASH,
      sym_id,
      sym_name,
      sym_class,
  [139] = 4,
    ACTIONS(45), 1,
      anon_sym_RPAREN,
    ACTIONS(47), 1,
      sym_attribute_name,
    STATE(17), 1,
      aux_sym_html_attributes_repeat1,
    STATE(19), 1,
      sym_attribute,
  [152] = 3,
    ACTIONS(49), 1,
      anon_sym_SPACE,
    ACTIONS(53), 1,
      anon_sym_EQ,
    ACTIONS(51), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [163] = 1,
    ACTIONS(39), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [170] = 4,
    ACTIONS(47), 1,
      sym_attribute_name,
    ACTIONS(55), 1,
      anon_sym_RPAREN,
    STATE(12), 1,
      aux_sym_html_attributes_repeat1,
    STATE(19), 1,
      sym_attribute,
  [183] = 1,
    ACTIONS(17), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [190] = 4,
    ACTIONS(57), 1,
      anon_sym_RPAREN,
    ACTIONS(59), 1,
      sym_attribute_name,
    STATE(17), 1,
      aux_sym_html_attributes_repeat1,
    STATE(19), 1,
      sym_attribute,
  [203] = 1,
    ACTIONS(62), 4,
      ts_builtin_sym_end,
      sym_id,
      sym_name,
      sym_class,
  [210] = 2,
    ACTIONS(64), 1,
      anon_sym_SPACE,
    ACTIONS(66), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [218] = 3,
    ACTIONS(68), 1,
      anon_sym_SQUOTE,
    ACTIONS(70), 1,
      anon_sym_DQUOTE,
    STATE(21), 1,
      sym_quoted_attribute_value,
  [228] = 2,
    ACTIONS(72), 1,
      anon_sym_SPACE,
    ACTIONS(74), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [236] = 2,
    ACTIONS(76), 1,
      anon_sym_SPACE,
    ACTIONS(78), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [244] = 2,
    ACTIONS(80), 1,
      anon_sym_SPACE,
    ACTIONS(82), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [252] = 1,
    ACTIONS(57), 2,
      anon_sym_RPAREN,
      sym_attribute_name,
  [257] = 2,
    ACTIONS(84), 1,
      anon_sym_SQUOTE,
    ACTIONS(86), 1,
      aux_sym_quoted_attribute_value_token1,
  [264] = 2,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(88), 1,
      aux_sym_quoted_attribute_value_token1,
  [271] = 1,
    ACTIONS(90), 1,
      ts_builtin_sym_end,
  [275] = 1,
    ACTIONS(92), 1,
      anon_sym_SQUOTE,
  [279] = 1,
    ACTIONS(92), 1,
      anon_sym_DQUOTE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 27,
  [SMALL_STATE(4)] = 54,
  [SMALL_STATE(5)] = 69,
  [SMALL_STATE(6)] = 82,
  [SMALL_STATE(7)] = 95,
  [SMALL_STATE(8)] = 103,
  [SMALL_STATE(9)] = 111,
  [SMALL_STATE(10)] = 121,
  [SMALL_STATE(11)] = 131,
  [SMALL_STATE(12)] = 139,
  [SMALL_STATE(13)] = 152,
  [SMALL_STATE(14)] = 163,
  [SMALL_STATE(15)] = 170,
  [SMALL_STATE(16)] = 183,
  [SMALL_STATE(17)] = 190,
  [SMALL_STATE(18)] = 203,
  [SMALL_STATE(19)] = 210,
  [SMALL_STATE(20)] = 218,
  [SMALL_STATE(21)] = 228,
  [SMALL_STATE(22)] = 236,
  [SMALL_STATE(23)] = 244,
  [SMALL_STATE(24)] = 252,
  [SMALL_STATE(25)] = 257,
  [SMALL_STATE(26)] = 264,
  [SMALL_STATE(27)] = 271,
  [SMALL_STATE(28)] = 275,
  [SMALL_STATE(29)] = 279,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 1, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2, 0, 0),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_tag_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_html_attributes, 3, 0, 0),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attributes, 1, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3, 0, 0),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_html_attributes, 2, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1, 0, 0),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_html_attributes_repeat1, 2, 0, 0),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_html_attributes_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 4, 0, 0),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_html_attributes_repeat1, 1, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 2, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_quoted_attribute_value, 3, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [90] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
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

static const bool ts_external_scanner_states[3][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__newline] = true,
    [ts_external_token__indent] = true,
    [ts_external_token__dedent] = true,
    [ts_external_token_ruby_attributes] = true,
  },
  [2] = {
    [ts_external_token_ruby_attributes] = true,
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
