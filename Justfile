# Generate the parser
generate:
    @npx tree-sitter generate

# Run the tests
test *ARGS: generate
    @npx tree-sitter test {{ARGS}}
