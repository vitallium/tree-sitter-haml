const assert = require("node:assert");
const { test } = require("node:test");

const Parser = require("tree-sitter");
const Haml = require(".");

test("can load grammar", () => {
  const parser = new Parser();
  assert.doesNotThrow(() => parser.setLanguage(Haml));
});

test("exposes only the outer Ruby attribute braces", () => {
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
    [10, 46],
  );

  assert.deepStrictEqual(
    rubyAttributes.descendantsOfType("ruby_attribute_hash"),
    [],
  );
  assert.strictEqual(rubyAttributes.text, '{:data => {:book => {:label => "}"}}}');
});

test("leaves Ruby literal and comment braces to the injected grammar", () => {
  const parser = new Parser();
  parser.setLanguage(Haml);
  const query = new Parser.Query(Haml, '("{" @open "}" @close)');
  const injectionQuery = new Parser.Query(
    Haml,
    require("node:fs").readFileSync(
      require("node:path").join(__dirname, "../../queries/injections.scm"),
      "utf8",
    ),
  );
  const cases = [
    "%div{text: %q({})}\n",
    "%div{text: %Q({})}\n",
    "%div{a: 1, # {}\n  b: 2}\n",
    "%div{pattern: /a{1,3}/}\n",
    "%div{text: <<~TEXT\n{}\nTEXT\n}\n",
    "%div{text: `echo {}`}\n",
    "%div{}\n",
    "%div{\r\n  data: {id: 1},\r\n\r\n}\r\n",
  ];

  for (const source of cases) {
    const tree = parser.parse(source);
    assert.strictEqual(tree.rootNode.hasError, false, source);
    const attributes = tree.rootNode.descendantsOfType("ruby_attributes")[0];
    const end = source.lastIndexOf("}") + 1;
    assert.deepStrictEqual(
      query.captures(tree.rootNode).map(({ node }) => node.startIndex),
      [4, end - 1],
      source,
    );
    assert.deepStrictEqual(
      injectionQuery.captures(tree.rootNode)
        .filter(({ name }) => name === "injection.content")
        .map(({ node }) => [node.startIndex, node.endIndex]),
      [[4, end]],
      source,
    );
    assert.strictEqual(attributes.text, source.slice(4, end));
  }
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
