cmake_minimum_required(VERSION 3.11.4)

# see https://cmake.org/cmake/help/latest/module/FetchContent.html
include(FetchContent)

include(CTest)
include(GoogleTest)
enable_testing()


FetchContent_Declare(
   googletest         GIT_TAG  v1.10.x
   GIT_REPOSITORY https://github.com/google/googletest.git )
FetchContent_GetProperties(googletest)

FetchContent_MakeAvailable(
  googletest
  )

add_executable(unitTests
        allTests.cc
        util.cc
        ValueClassTest.cc
        ObjectClassTest.cc
        AnotherValueTest.cc
        stdlibTest.cc boostLib.cc follyTests.cc fmtLibTest.cc)
target_link_libraries(unitTests
        PUBLIC cppclasses
        gtest
        gmock )
target_include_directories(unitTests
        PUBLIC cppclasses
        gtest
        gmock )
target_compile_features(unitTests PRIVATE cxx_std_20)

gtest_discover_tests(unitTests
  WORKING_DIRECTORY ${PROJECT_DIR}
  PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}" )
set_target_properties(unitTests PROPERTIES FOLDER tests)
