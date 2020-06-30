# Sample CMake project

This project contains:

    - some sample classes,
    - CLion file templates for generating C++ classes
    - some CMake files to demonstrate how to arrange project
    - Google tests for the sample classes.

This project makes use of the:

    - [C++ standard library](https://en.cppreference.com/w/cpp/header)
    - [Boost library](https://www.boost.org/doc/libs/)
    - [Facebook Folly](https://github.com/facebook/folly )

# Initial Setup

The extern folder contains a script that must be run to install packages needed
by folly. Additionally the build.sh script in that folder should be run


```
   $ cd $PROJECT_ROOT
   $ cd extern
   $ ./initialSetup.sh
   $ ./build.sh -j {num-processors}
   
```

NOTE the initialSetup.sh script installs a number of libraries
required by Facebook's folly library. You can choose to use these
older versions or add ones to the CMakeLists.txt file as external
projects.

# Building

Once the 3rd party libraries have been installed and/or built, you can
proceed building the sample project:


```
   $ cd $PROJECT_ROOT
   $ ./build.sh -j {num-processors}

   # to execute the tests using ctest
   $ ./test.sh # run with --help to see the list of options to pass to ctest
```
# Optional Clion setup

AFTER you've opened the project in CLion, you can install the clion file
templates as follows:

```
   $ cd $PROJECT_ROOT
   $ cd clion
   $ tar cf - --exclude=Readme.md . |(cd ../.idea/fileTemplates; tar xvf - )

```

You'll most likely need to restart clion to see the templates.

# References
    - [C++ standard library](https://en.cppreference.com/w/cpp/header)
    - [Boost library](https://www.boost.org/doc/libs/)
    - [Markdown Guide](https://www.markdownguide.org/cheat-sheet/)
    - [C++Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)
    
