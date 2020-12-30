cc_library(
  name = "iasm-lib",
  srcs = [
    "fmap.cpp",
    "memory.cpp",
    "op.cpp",
    "registers.cpp",
    "util.cpp",
  ],
  hdrs = [
    "asm_types.hpp",
    "fmap.hpp",
    "imports.hpp",
    "memory.hpp",
    "op.hpp",
    "registers.hpp",
    "util.hpp",
  ],
)

cc_binary(
  name = "iasm",
  srcs = [
    "asm_main.cpp",
  ],
  deps = [
    ":iasm-lib",
  ],
)
