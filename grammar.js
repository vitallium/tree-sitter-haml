/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "haml",
  externals: ($) => [$._newline, $._indent, $._dedent, $.ruby_attributes],
  rules: {
    source_file: ($) =>
      repeat(
        choice(
          $.doctype,
          $.tag,
          $.comment,
          $.ruby_block_output,
          $.ruby_block_run,
          $.ruby_interpolation,
          $.filter,
        ),
      ),
    doctype: ($) => seq("!!!", $._text),
    tag: ($) =>
      seq(
        choice($.tag_name, $.id, $.class),
        optional(repeat1(choice($.tag_name, $.id, $.class))),
        optional($.attributes),
        optional(alias("/", $.self_close_slash)),
        choice(
          $.ruby_block_output,
          seq(" ", $.verbatim_string),
          seq($._newline, optional($._children)),
        ),
      ),
    _children: ($) =>
      prec.right(
        seq($._indent, repeat1($._children_choice), optional($._dedent)),
      ),
    _children_choice: ($) =>
      choice(
        $.tag,
        $.ruby_block_output,
        $.ruby_block_run,
        $.ruby_interpolation,
        $.filter,
        $.verbatim_string,
        $.comment,
        $._newline,
      ),
    html_attributes: ($) =>
      seq("(", repeat(seq($.attribute, optional(" "))), ")"),
    attributes: ($) => choice($.html_attributes, $.ruby_attributes),
    // Starts with %
    tag_name: () => /%[-:\w]+/,
    class_or_id_value: () => /[-:_a-zA-Z0-9\@]+/,
    // Starts with #
    id: ($) => seq("#", alias($.class_or_id_value, "id")),
    // Starts with `.` (dot)
    class: ($) => seq(".", $.class_name),
    class_name: () => /[-:_a-zA-Z0-9\@]+/,
    comment: ($) => choice($._comment_line, $._comment_block),
    // HTML Comments starts with /
    _comment_line: ($) =>
      seq(
        choice("/", "-#"),
        $._text,
        $._newline,
        optional(seq($._indent, repeat1(seq($._text, $._newline)), $._dedent)),
      ),
    _comment_block: ($) =>
      seq(
        choice("/", "-#"),
        optional($.comment_condition),
        $._newline,
        $._indent,
        repeat1(seq($._text, $._newline)),
        $._dedent,
      ),
    comment_condition: ($) => seq("[", $._text, "]"),
    attribute_name: () => /#?[\w@\-:]+/,
    attribute: ($) =>
      seq($.attribute_name, optional(seq("=", $.quoted_attribute_value))),
    quoted_attribute_value: ($) =>
      choice(
        seq(
          "'",
          repeat1(
            choice(
              $.ruby_interpolation,
              alias($._html_identifier, $.attribute_value),
            ),
          ),
          "'",
        ),
        seq(
          '"',
          repeat1(
            choice(
              $.ruby_interpolation,
              alias($._html_identifier, $.attribute_value),
            ),
          ),
          '"',
        ),
      ),
    _text: () => /[^\n]*/,
    verbatim_string: ($) => token(prec(-1, /[^\n]+/)),
    ruby_block_output: ($) =>
      seq(
        optional("!"),
        "=",
        alias($._text, $.ruby_code),
        seq($._newline, optional($._children)),
      ),
    ruby_block_run: ($) =>
      seq(
        "-",
        alias($._text, $.ruby_code),
        seq($._newline, optional($._children)),
      ),
    ruby_interpolation: ($) => seq("#", $.ruby_expression),
    ruby_expression: () => /\{[^}]*\}/,
    _html_identifier: () => /[-:\w/.]+/,
    filter: ($) =>
      seq(
        ":",
        alias($._text, $.filter_name),
        $._newline,
        optional($.filter_body),
      ),
    filter_body: ($) =>
      prec.right(
        seq(
          $._indent,
          repeat1(choice(seq($._text, $._newline), $._newline)),
          optional($._dedent),
        ),
      ),
  },
});
