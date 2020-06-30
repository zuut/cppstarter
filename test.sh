#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}" )"


fatal() {
    echo >&2 "$*"
    exit 1
}


[ ! -z "$(type -p cmake)" ] || fatal "Unable to find cmake"
[ ! -z "$(type -p ctest)" ] || fatal "Unable to find ctest"


CMAKE_BUILD_TYPE=Debug
CMAKE_BUILD_DIR=cmake-build-debug

[ -e "${CMAKE_BUILD_DIR}/test/unitTests" ] || fatal "Run the build first"

cd "${CMAKE_BUILD_DIR}/test/"

export GTEST_COLOR=1
exec ctest -V "$@"



