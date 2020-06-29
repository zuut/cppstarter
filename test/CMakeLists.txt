cmake_minimum_required(VERSION 3.3)

project(CppSandboxTest)

include(CTest)
enable_testing()

add_executable(unitTests
        allTests.cc
        util.cc
        ValueClassTest.cc
        ObjectClassTest.cc
        AnotherValueTest.cc
        stdlibTest.cc boostLib.cc)
target_link_libraries(unitTests
        PUBLIC cppclasses
        gtest
        gmock )
target_include_directories(unitTests
        PUBLIC cppclasses
        gtest
        gmock )
add_test(NAME valueClass COMMAND ValueClassTest)
add_test(NAME anotherValueClass COMMAND AnotherValueClassTest)
add_test(NAME objectClass COMMAND ObjectClassTest)
