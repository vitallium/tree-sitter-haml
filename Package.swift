// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterHaml",
    products: [
        .library(name: "TreeSitterHaml", targets: ["TreeSitterHaml"])
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.9.0")
    ],
    targets: [
        .target(
            name: "TreeSitterHaml",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                "src/scanner.c",
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterHamlTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterHaml",
            ],
            path: "bindings/swift/TreeSitterHamlTests"
        ),
    ],
    cLanguageStandard: .c11
)
