#!/bin/bash
cd "$(dirname "${BASH_SOURCE[0]}" )"
scriptDir=$(pwd)
MANUAL_BUILDS="$scriptDir/cmake-build-manual"


fatal() {
    echo >&2 "$*"
    exit 1
}

SUDO=""
if [ "$(id -u)" != "0" ]; then
  SUDO="sudo"
fi

$SUDO apt-get install -y \
    g++ \
    cmake \
    libboost-all-dev \
    libevent-dev \
    libdouble-conversion-dev \
    libgoogle-glog-dev \
    libgflags-dev \
    libiberty-dev \
    liblz4-dev \
    liblzma-dev \
    libsnappy-dev \
    make \
    zlib1g-dev \
    binutils-dev \
    libjemalloc-dev \
    libssl-dev \
    pkg-config \
    libunwind-dev \
    libfmt-dev

mkdir -p "$MANUAL_BUILDS"
cd "$MANUAL_BUILDS"

git clone https://github.com/fmtlib/fmt.git && cd fmt
mkdir _buil && cd _build && cmake .. && make && $SUDO make install

cd $scriptDir

$SUDO apt-get install -y \
    libunwind8-dev \
    libelf-dev \
    libdwarf-dev
