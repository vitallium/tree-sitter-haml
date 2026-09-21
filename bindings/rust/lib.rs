//! This crate provides Haml language support for the [tree-sitter][] parsing library.
//!
//! Typically, you will use the [LANGUAGE][] constant to add this language to a
//! tree-sitter [Parser][], and then use the parser to parse some code:
//!
//! ```
//! let code = r#"
//! "#;
//! let mut parser = tree_sitter::Parser::new();
//! let language = tree_sitter_haml::LANGUAGE;
//! parser
//!     .set_language(&language.into())
//!     .expect("Error loading Haml parser");
//! let tree = parser.parse(code, None).unwrap();
//! assert!(!tree.root_node().has_error());
//! ```
//!
//! [Parser]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Parser.html
//! [tree-sitter]: https://tree-sitter.github.io/

use tree_sitter_language::LanguageFn;

extern "C" {
    fn tree_sitter_haml() -> *const ();
}

/// The tree-sitter [`LanguageFn`][LanguageFn] for this grammar.
///
/// [LanguageFn]: https://docs.rs/tree-sitter-language/*/tree_sitter_language/struct.LanguageFn.html
pub const LANGUAGE: LanguageFn = unsafe { LanguageFn::from_raw(tree_sitter_haml) };

/// The content of the [`node-types.json`][] file for this grammar.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const NODE_TYPES: &str = include_str!("../../src/node-types.json");

// NOTE: uncomment these to include any queries that this grammar contains:

pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/highlights.scm");
pub const INJECTIONS_QUERY: &str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &str = include_str!("../../queries/locals.scm");
// pub const TAGS_QUERY: &str = include_str!("../../queries/tags.scm");

#[cfg(test)]
mod tests {
    #[test]
    fn test_can_load_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE.into())
            .expect("Error loading Haml parser");
    }

    #[test]
    fn indented_tokens_start_after_whitespace() {
        let tree = parse("%a\n  %b\n    %c\n      %d\n  %e\n    %f\n");
        assert!(!tree.root_node().has_error());

        let mut columns = Vec::new();
        collect_tag_name_columns(tree.root_node(), &mut columns);

        assert_eq!(columns, [0, 2, 4, 6, 2, 4]);
    }

    #[test]
    fn nonmatching_dedent_does_not_leak() {
        let tree = parse("%p\n  %b\n %c\n");
        assert!(!tree.root_node().has_error());
    }

    #[test]
    fn indented_first_line_tracks_nested_levels() {
        let tree = parse("  %a\n    %b\n  %c\n");
        assert!(!tree.root_node().has_error());

        let mut columns = Vec::new();
        collect_tag_name_columns(tree.root_node(), &mut columns);
        assert_eq!(columns, [2, 4, 2]);
    }

    fn parse(source: &str) -> tree_sitter::Tree {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE.into())
            .expect("Error loading Haml parser");
        parser.parse(source, None).unwrap()
    }

    fn collect_tag_name_columns(node: tree_sitter::Node, columns: &mut Vec<usize>) {
        if node.kind() == "tag_name" {
            columns.push(node.start_position().column);
        }

        let mut cursor = node.walk();
        for child in node.children(&mut cursor) {
            collect_tag_name_columns(child, columns);
        }
    }
}
