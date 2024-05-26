/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "haml",
  externals: ($) => [$._newline, $._indent, $._dedent, $.ruby_attributes],
  rules: {
    source_file: ($) => repeat(choice($.tag)),
    tag: ($) =>
      prec.right(
        seq(
          choice($.name, $.id, $.class),
          optional(repeat1(choice($.name, $.id, $.class))),
          optional($.attributes),
          optional(alias("/", $.self_close_slash)),
          // choice(
          //   seq(
          //     optional(seq($._newline, $._indent)),
          //     optional(" "),
          //     $.buffered_code,
          //   ),
          //   seq($._newline, optional($.children)),
          // ),
        ),
      ),
    children: ($) =>
      prec.right(
        seq($._indent, repeat1($._children_choice), optional($._dedent)),
      ),
    _children_choice: ($) => prec(1, choice($.tag, $.text, $._newline)),
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
    text: () => /[^\n]+/,
    buffered_code: ($) => prec.right(seq("=", $.text, optional($._newline))),
  },
});
