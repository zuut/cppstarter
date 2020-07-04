find_package(Boost 1.65
    COMPONENTS
        # see: https://www.boost.org/doc/libs/
        filesystem
        system
    REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(Threads REQUIRED)
find_package(Folly REQUIRED)

add_library(cxxclasses
        ObjectClass.cc
    ValueClass.cc
    AnotherValueClass.cc
        util.h
    util.cc ../include/cxxstarter/ClassTemplate.h)
target_include_directories(cxxclasses
        PUBLIC ../include )

target_link_libraries(cxxclasses
        PUBLIC Boost::system
               gflags
               Folly::folly )
target_compile_features(cxxclasses PRIVATE cxx_std_20)

#
# Executable
#
add_executable(cxxstarter
    main.cc)
target_link_libraries(cxxstarter
    cxxclasses)
