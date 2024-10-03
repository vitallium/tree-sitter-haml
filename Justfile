generate:
    @npx tree-sitter generate

test: generate
    @npx tree-sitter test
