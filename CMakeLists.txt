cmake_minimum_required(VERSION 3.2)
project(cxxstarter)

set(EXTERN_PROJECTS_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/extern/installed )
if (NOT EXISTS ${EXTERN_PROJECTS_INSTALL_PREFIX} )
  message(SEND_ERROR "Missing '${EXTERN_PROJECTS_INSTALL_PREFIX}' " )
  message(FATAL_ERROR "You must build the extern libraries under extern directory")
endif()

set(CMAKE_PREFIX_PATH ${EXTERN_PROJECTS_INSTALL_PREFIX} ${EXTERN_PROJECTS_INSTALL_PREFIX}/lib ${EXTERN_PROJECTS_INSTALL_PREFIX}/include )

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(test)
