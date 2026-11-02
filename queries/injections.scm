((ruby_code) @injection.content
  (#set! injection.language "ruby"))

((ruby_attributes) @injection.content
  (#set! injection.language "ruby"))

(filter
  (filter_name) @injection.language
  (filter_body) @injection.content)
