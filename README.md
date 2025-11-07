# tree-sitter-haml

This is a general tree-sitter parser grammar for [the HAML templating language](https://haml.info/).

## Development

### Building

To build the grammar, run:

```shell
npm run build
```

### Registering the grammar

If you want the `tree-sitter` CLI to pick up this grammar after building it, add the repository to your parser directories:

1. Ensure you have a config file (`tree-sitter init-config` creates `~/.config/tree-sitter/config.json` if it is missing).
2. Edit that file and include the absolute path to this repo in the `parser-directories` array, for example:

   ```json
   {
     "parser-directories": [
       "/Users/you/path/to/tree-sitter-haml"
     ]
   }
   ```

Once registered, commands like `tree-sitter parse` and `tree-sitter highlight` will automatically load the HAML parser from this build.

### Testing

To test the grammar, run:

```shell
npm run test
```

## Contributing

Contributions are welcome! Please open an issue or submit a pull request.

## Credits

- [The `pug` grammar](https://github.com/zealot128/tree-sitter-pug/blob/master/README.md)

## References

- [Tree-sitter](https://tree-sitter.github.io/tree-sitter/)
- [Tree-sitter documentation](https://tree-sitter.github.io/tree-sitter/creating-parsers)
- [HAML](https://haml.info/)
- [HAML documentation](https://haml.info/docs/yardoc/file.REFERENCE.html)
