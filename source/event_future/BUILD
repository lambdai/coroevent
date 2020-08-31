load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "event_future_lib",
    srcs = ["event_future.cc"],
    hdrs = ["event_future.h"],
    deps = [
        "@libevent",
    ],
)

cc_test(
    name = "event_future_test",
    srcs = ["event_future_test.cc"],
    deps = [
        ":event_future_lib",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)
