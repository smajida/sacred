py_binary(
  name = 'group_by',
  srcs = [
    'group_by.py',
  ],
)

sh_binary(
  name = 'group_consecutive_utterances',
  srcs = [
    'group_consecutive_utterances.sh',
  ],
)

cc_binary(
  name = 'print_floats',
  srcs = [
    'print_floats.cpp',
  ],
  deps = [
    '//external:googleflags',
  ],
)

py_binary(
  name = 'prepare_data',
  srcs = [
    'prepare_data.py',
  ],
)

py_binary(
  name = 'proto3',
  srcs = [
    'proto3.py',
  ],
  deps = [
    '//sacred/proto:conversation',
  ],
)

py_binary(
  name = 'replace_unknown_words',
  srcs = [
    'replace_unknown_words.py',
  ],
)
