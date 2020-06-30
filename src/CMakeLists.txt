find_package(Boost 1.65
    COMPONENTS
        # see: https://www.boost.org/doc/libs/
        filesystem
        system
    REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(Threads REQUIRED)
find_package(Folly REQUIRED)

add_library(cppclasses
        ObjectClass.cc
    ValueClass.cc
    AnotherValueClass.cc
        util.h
    util.cc ../include/cppsandbox/ClassTemplate.h)
target_include_directories(cppclasses
        PUBLIC ../include )

target_link_libraries(cppclasses
        PUBLIC Boost::system
               gflags
               Folly::folly )
target_compile_features(cppclasses PRIVATE cxx_std_20)

#
# Executable
#
add_executable(cppsandbox
    main.cc)
target_link_libraries(cppsandbox
        cppclasses)
