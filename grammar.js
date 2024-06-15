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
          seq(" ", $.text_content),
          $.ruby_block_output,
          seq($._newline, optional($._children)),
        ),
      ),
    _children: ($) =>
      prec.right(
        seq($._indent, repeat1($._children_choice), optional($._dedent)),
      ),
    _children_choice: ($) =>
      prec(
        1,
        choice(
          $.text_content,
          $.ruby_block_output,
          $.ruby_block_run,
          $.ruby_interpolation,
          $.tag,
          $._newline,
        ),
      ),
    html_attributes: ($) =>
      seq("(", repeat(seq($.attribute, optional(" "))), ")"),
    attributes: ($) => choice($.html_attributes, $.ruby_attributes),
    value: () => /[^\n}]+/,
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
        seq("'", optional(alias(/([-:\w/.]+)/, $.attribute_value)), "'"),
        seq('"', optional(alias(/([-:\w/.]+)/, $.attribute_value)), '"'),
      ),
    _text: () => /(.)+?/,
    text_content: ($) => $._text,
    ruby_block_output: ($) => seq("=", $._text),
    ruby_block_run: ($) => seq("-", $._text),
    // FIXME: Ruby interpolation should not be mapped to Ruby attributes
    ruby_interpolation: ($) => seq("#", $.ruby_attributes),
  },
});
