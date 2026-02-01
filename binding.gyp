{
  "targets": [
    {
      "target_name": "tree_sitter_haml_binding",
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api_except",
      ],
      "include_dirs": [
        "src",
      ],
      "sources": [
        "bindings/node/binding.cc",
        "src/parser.c",
        "src/scanner.c",
      ],
      "conditions": [
        ["OS=='mac'", {
          "xcode_settings": {
            "GCC_SYMBOLS_PRIVATE_EXTERN": "YES", # -fvisibility=hidden
            "CLANG_CXX_LANGUAGE_STANDARD": "<(cxxstd)",
            "MACOSX_DEPLOYMENT_TARGET": "10.9",
          },
        }],
        ["OS=='win'", {
          "msvs_settings": {
            "VCCLCompilerTool": {
              "AdditionalOptions": [
                "/std:<(cxxstd)",
              ],
              "RuntimeLibrary": 0,
            },
          },
        }],
        ["OS == 'linux'", {
          "cflags_cc": [
            "-std=<(cxxstd)",
            "-fvisibility=hidden",
            "-Wno-cast-function-type",
          ]
        }],
      ],
    }
  ],
  "variables": {
    "cxxstd%": "<!(node -p \"parseInt(process.env.npm_config_target ?? process.versions.node) < 22 ? 'c++17' : 'c++20'\")",
  }
}
