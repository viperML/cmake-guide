# Required: more features are available in newer versions
# If unsure, use the result of "cmake --version"
cmake_minimum_required(VERSION 3.16)

# This library uses different names, but you can choose to use
# the same name for everything:
# - mylib: name of the CMake target for the library <- Important
# - myproject: name of the project (mostly useless)
# - mylib-targets, mylib-config: the first part must match how the library is found,
#   e.g. find_package(some_name) -> some_name-targets, some_name-config
# - MyLib:: name of the CMake namespace (not C++ namespace). The target mylib will be
#   namespaces, as MyLib::mylib (NamespaceName::targetName) for the consumers of your library.

# If you want, you might as well use the same name for everything

project(myproject VERSION 0.1 LANGUAGES CXX)

# This brings CMAKE_INSTALL_LIBDIR, etc
include(GNUInstallDirs)

# Crate a new library target
add_library(mylib SHARED mylib.cpp)

# For the library target, the headers will have a different location if
# it's referred to as the installed or developed library
target_include_directories(
    mylib
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> # when writing the library
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}> # when installing the library
)

# Install the library
# EXPORT creates an export group
install(
    TARGETS mylib
    EXPORT mylib-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install the headers
install(
    FILES mylib.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# For the export group we created, install it as "mylib-targets.cmake"
install(
    EXPORT mylib-targets
    NAMESPACE MyLib::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/mylib"
)

# If the user uses the project with add_subdirectory,
# also provide the target with the namespace as an alias
add_library(MyLib::mylib ALIAS mylib)

# Install the configuration file
install(
    FILES mylib-config.cmake
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/mylib"
)


# When consumers of the library call find_package(mylib REQUIRED),
# CMake will look in the standar paths (/usr/lib) and CMAKE_PREFIX_PATH
# for a file "mylib-config.cmake"
# This is a "shim", that simply loads our exports from "mylib-targets.cmake"

# You must modify your "mylib-config.cmake" file in this repo if you change
# the name of the library
