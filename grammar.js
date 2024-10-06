/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "haml",
  externals: ($) => [$._newline, $._indent, $._dedent, $.ruby_attributes],
  rules: {
    source_file: ($) =>
      repeat(
        choice(
          $.tag,
          $.comment,
          $.ruby_block_output,
          $.ruby_block_run,
          $.ruby_interpolation,
        ),
      ),
    tag: ($) =>
      seq(
        choice($.tag_name, $.id, $.class),
        optional(repeat1(choice($.tag_name, $.id, $.class))),
        optional($.attributes),
        optional(alias("/", $.self_close_slash)),
        choice(
          $.ruby_block_output,
          seq(" ", $.text_content),
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
        $.text_content,
        $.comment,
      ),
    html_attributes: ($) =>
      seq("(", repeat(seq($.attribute, optional(" "))), ")"),
    attributes: ($) => choice($.html_attributes, $.ruby_attributes),
    // Starts with #
    id: () => /#[\w-]+/,
    // Starts with %
    tag_name: () => /%([-:\w]+)/,
    // Starts with . (dot)
    class_name: () => /[_a-z0-9\-]*[_a-zA-Z][_a-zA-Z0-9\-]*/i,
    comment: ($) => choice($._comment_line, $._comment_block),
    // HTML Comments starts with /
    _comment_line: ($) =>
      seq(
        choice("/", "-#"),
        $._comment_content,
        $._newline,
        optional(
          seq(
            $._indent,
            repeat1(seq($._comment_content, $._newline)),
            $._dedent,
          ),
        ),
      ),
    _comment_block: ($) =>
      seq(
        choice("/", "-#"),
        optional($.comment_condition),
        $._newline,
        $._indent,
        repeat1(seq($._comment_content, $._newline)),
        $._dedent,
      ),
    comment_condition: ($) => seq("[", $._text, "]"),
    class: ($) => seq(".", $.class_name),
    attribute_name: () => /#?[\w@\-:]+/,
    attribute: ($) =>
      seq($.attribute_name, optional(seq("=", $.quoted_attribute_value))),
    quoted_attribute_value: ($) =>
      choice(
        seq("'", optional(alias($._html_identifier, $.attribute_value)), "'"),
        seq('"', optional(alias($._html_identifier, $.attribute_value)), '"'),
      ),
    _text: () => /[^\n]+/,
    _comment_content: () => /[^\n]*/,
    text_content: ($) => token(prec(-1, /[^\n]+/)),
    ruby_block_output: ($) =>
      seq(
        "=",
        alias($._text, $.ruby_code),
        optional(seq($._newline, optional($._children))),
      ),
    ruby_block_run: ($) =>
      seq(
        "-",
        alias($._text, $.ruby_code),
        optional(seq($._newline, optional($._children))),
      ),
    ruby_interpolation: ($) => seq("#", $.ruby_expression),
    ruby_expression: () => /\{[^}]*\}/,
    _html_identifier: () => /[-:\w/.]+/,
  },
});
