load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")

package(default_visibility = ["//visibility:public"])

DEFAULT_EMSCRIPTEN_LINKOPTS = [
    # LTO broken when using hermetic emsdk
    # "-flto",                            # Specify lto (has to be set on for compiler as well)
    "--bind",                           # Compiles the source code using the Embind bindings to connect C/C++ and JavaScript
    # Closure compiler broken when using hermetic emsdk
    # "--closure 1",                      # Run the closure compiler
    "-s MALLOC=emmalloc",               # Switch to using the much smaller implementation
    "-s ALLOW_MEMORY_GROWTH=0",         # Our example doesn't need memory growth
    "-s USE_PTHREADS=0",                # Disable pthreads
    "-s ASSERTIONS=0",                  # Turn off assertions
    "-s EXPORT_ES6=0",                  # Export as es6 module, used for rollup
    "-s MODULARIZE=0",                  # Allows us to manually invoke the initializatio of wasm
    "-s EXPORT_NAME=createModule",      # Not used, but good to specify
    "-s USE_ES6_IMPORT_META=0",         # Disable loading from import meta since we use rollup
    "-s SINGLE_FILE=1",                 # Pack all webassembly into base64
    "-s DISABLE_EXCEPTION_CATCHING=1",  # Disable all exception catching
    "-s NODEJS_CATCH_EXIT=0",           # We don't have a 'main' so disable exit() catching
    "-s EXTRA_EXPORTED_RUNTIME_METHODS=\"['ccall', 'cwrap', 'addOnPostRun']\" ",
]
ASMJS_LINKOPTS = [
    "-s WASM=0",                    # Specify asm.js output
]

WASM_LINKOPTS = [
    "-s WASM=1",                    # Specify wasm output
]

cc_binary(
    name = "hello-world-wasm.js",
    srcs = ["bindings/binding.cpp"],
    linkopts = DEFAULT_EMSCRIPTEN_LINKOPTS + WASM_LINKOPTS,
    deps = [
        "//hello-world/cpp:greet",
    ],
)

cc_binary(
    name = "hello-world-js.js",
    srcs = ["bindings/hello-world.cpp"],
    linkopts = DEFAULT_EMSCRIPTEN_LINKOPTS + ASMJS_LINKOPTS,
    deps = [
        "//hello-world/cpp:greet",
    ],
)

wasm_cc_binary(
    name = "hello-world-wasm",
    cc_target = ":hello-world-wasm.js",
)

wasm_cc_binary(
    name = "hello-world-js",
    cc_target = ":hello-world-js.js",
)
