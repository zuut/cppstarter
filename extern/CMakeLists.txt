cmake_minimum_required(VERSION 3.11.4)

project(cxxstarter_dependencies)

include (ExternalProject)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/installed )

set(GITHUB_ROOT https://github.com/)
set(PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_INSTALL_PREFIX})
set(DEFAULT_ARGS
  -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
  -DCMAKE_PREFIX_PATH=${PREFIX_PATH}
  -DCMAKE_BUILD_TYPE=RELWITHDEBINFO
  )

ExternalProject_Add(googletest
  GIT_REPOSITORY ${GITHUB_ROOT}google/googletest.git
  GIT_TAG v1.10.x
  CMAKE_ARGS
    ${DEFAULT_ARGS}
    -DBUILD_GTEST=1
)

ExternalProject_Add(double_conversion
  GIT_REPOSITORY ${GITHUB_ROOT}google/double-conversion.git
  GIT_TAG v3.1.5
  CMAKE_ARGS
    ${DEFAULT_ARGS}
)


ExternalProject_Add(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 6.2.1
  CMAKE_ARGS
    ${DEFAULT_ARGS}
    -DFMT_TEST=OFF
)

ExternalProject_Add(folly
  DEPENDS googletest
  GIT_REPOSITORY ${GITHUB_ROOT}facebook/folly.git
  GIT_TAG v2020.06.15.00
  CMAKE_ARGS
    ${DEFAULT_ARGS}
)







