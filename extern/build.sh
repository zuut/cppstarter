#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}" )"


fatal() {
    echo >&2 "$*"
    exit 1
}


[ ! -z "$(type -p cmake)" ] || fatal "Unable to find cmake"


CMAKE_BUILD_TYPE=Debug
CMAKE_BUILD_DIR=cmake-build-debug


mkdir -p "${CMAKE_BUILD_DIR}"
cd "${CMAKE_BUILD_DIR}"

echo cmake -k -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ..
cmake -k -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} ..
cmake --build . "$@"



