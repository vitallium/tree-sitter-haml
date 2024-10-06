package tree_sitter_haml_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_haml "github.com/tree-sitter/tree-sitter-haml/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_haml.Language())
	if language == nil {
		t.Errorf("Error loading Haml grammar")
	}
}
