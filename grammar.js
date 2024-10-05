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
          $.ruby_block_output,
          $.ruby_block_run,
          $.ruby_interpolation,
        ),
      ),
    tag: ($) =>
      seq(
        choice($.name, $.id, $.class),
        optional(repeat1(choice($.name, $.id, $.class))),
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
      ),
    html_attributes: ($) =>
      seq("(", repeat(seq($.attribute, optional(" "))), ")"),
    attributes: ($) => choice($.html_attributes, $.ruby_attributes),
    // Starts with #
    id: () => /#[\w-]+/,
    // Starts with %
    name: () => /%([-:\w]+)/,
    // Starts with . (dot)
    class: () => /\.[_a-z0-9\-]*[_a-zA-Z][_a-zA-Z0-9\-]*/i,
    attribute_name: () => /#?[\w@\-:]+/,
    attribute: ($) =>
      seq($.attribute_name, optional(seq("=", $.quoted_attribute_value))),
    quoted_attribute_value: ($) =>
      choice(
        seq("'", optional(alias($._html_identifier, $.attribute_value)), "'"),
        seq('"', optional(alias($._html_identifier, $.attribute_value)), '"'),
      ),
    _text: () => token(prec(-1, /[^\n]+/)),
    text_content: ($) => $._text,
    ruby_block_output: ($) => seq("=", $._text),
    ruby_block_run: ($) =>
      seq("-", $._text, optional(seq($._newline, optional($._children)))),
    ruby_interpolation: ($) => seq("#", $.ruby_expression),
    ruby_expression: () => /\{[^}]*\}/,
    _html_identifier: () => /[-:\w/.]+/,
  },
});
