load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "emsdk",
    sha256="d18d951f192bded1f7cb99f0d402663a2aa61db11d17f15a587ab22c37b0ee42",
    strip_prefix="emsdk-71780a80de0d4d8772406ab34549c5a5e26d7e51/bazel" ,
    url = "https://github.com/emscripten-core/emsdk/archive/71780a80de0d4d8772406ab34549c5a5e26d7e51.tar.gz",
)

load("@emsdk//:deps.bzl", emsdk_deps = "deps")
emsdk_deps()

load("@emsdk//:emscripten_deps.bzl", emsdk_emscripten_deps = "emscripten_deps")
emsdk_emscripten_deps()
