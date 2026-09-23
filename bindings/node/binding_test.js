const assert = require("node:assert");
const { test } = require("node:test");

const Parser = require("tree-sitter");
const Haml = require(".");

test("can load grammar", () => {
  const parser = new Parser();
  assert.doesNotThrow(() => parser.setLanguage(Haml));
});

test("exposes paired Ruby attribute hash braces", () => {
  const parser = new Parser();
  parser.setLanguage(Haml);

  const tree = parser.parse(
    '.book-info{:data => {:book => {:label => "}"}}}\n',
  );
  assert.strictEqual(tree.rootNode.hasError, false);

  const rubyAttributes =
    tree.rootNode.descendantsOfType("ruby_attributes")[0];

  assert.deepStrictEqual(
    rubyAttributes
      .descendantsOfType(["{", "}"])
      .map((node) => node.startIndex),
    [10, 20, 30, 44, 45, 46],
  );

  const hashes = [
    rubyAttributes,
    ...rubyAttributes.descendantsOfType("ruby_attribute_hash"),
  ];
  assert.deepStrictEqual(
    hashes.map((node) => node.text),
    [
      '{:data => {:book => {:label => "}"}}}',
      '{:book => {:label => "}"}}',
      '{:label => "}"}',
    ],
  );
});

test("recovers from an unterminated Ruby attribute hash", () => {
  const parser = new Parser();
  parser.setLanguage(Haml);

  const cases = [
    ["%div{\n", ["%div"]],
    ["%div{:a => 1\n", ["%div"]],
    ["%div{:a => 1}}\n", ["%div"]],
    ["%div{\n  %p hi\n%footer Bye\n", ["%div", "%p", "%footer"]],
  ];

  for (const [source, tagNames] of cases) {
    const tree = parser.parse(source);

    assert.strictEqual(tree.rootNode.hasError, true);
    assert.deepStrictEqual(
      tree.rootNode.descendantsOfType("tag_name").map((node) => node.text),
      tagNames,
    );
  }
});
