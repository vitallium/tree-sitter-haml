(filter
  (filter_name) @injection.language
  (filter_body) @injection.content)

((ruby_code) @injection.content
  (#set! injection.language "ruby"))
