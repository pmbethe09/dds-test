workspace(name = "com_github_pmbethe09_dds_test")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

new_git_repository(
    name = "com_github_dds_bridge_dds",
    build_file = "//:BUILD.dds",
    remote = "https://github.com/dds-bridge/dds",
    tag = "v2.8.4",
)

http_archive(
    name = "com_github_google_googletest",
    sha256 = "443d383db648ebb8e391382c0ab63263b7091d03197f304390baac10f178a468",
    strip_prefix = "googletest-c9ccac7cb7345901884aabf5d1a786cfa6e2f397",
    url = "https://github.com/google/googletest/archive/c9ccac7cb7345901884aabf5d1a786cfa6e2f397.tar.gz",  # 2019-08-19
)
