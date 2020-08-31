workspace(name = "coroevent")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

#all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

# Rule repository
http_archive(
   name = "rules_foreign_cc",
   sha256 = "7ca49ac5b0bc8f5a2c9a7e87b7f86aca604bda197259c9b96f8b7f0a4f38b57b",
   strip_prefix = "rules_foreign_cc-f54b7ae56dcf1b81bcafed3a08d58fc08ac095a7",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/f54b7ae56dcf1b81bcafed3a08d58fc08ac095a7.tar.gz",
)
   
load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies([])


http_archive(
    name = "libevent",
    urls = [
        "https://github.com/libevent/libevent/archive/release-2.1.12-stable.tar.gz"
    ],
    sha256 = "7180a979aaa7000e1264da484f712d403fcf7679b1e9212c4e3d09f5c93efc24",
    strip_prefix = "libevent-release-2.1.12-stable",
    build_file = "//bazel:libevent.BUILD"
)

http_archive(
    name = "gtest",
    url = "https://github.com/google/googletest/archive/release-1.10.0.tar.gz",
    sha256 = "9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb",
    strip_prefix = "googletest-release-1.10.0",
    build_file = "//bazel:gtest.BUILD",
)