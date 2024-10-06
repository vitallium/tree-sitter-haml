import XCTest
import SwiftTreeSitter
import TreeSitterHaml

final class TreeSitterHamlTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_haml())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Haml grammar")
    }
}