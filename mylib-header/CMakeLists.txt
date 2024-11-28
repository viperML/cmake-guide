cmake_minimum_required(VERSION 3.16)

project(mylib-header LANGUAGES CXX)

include(GNUInstallDirs)

add_library(mylib-header INTERFACE)
target_include_directories(
    mylib-header
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> # when writing the library
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}> # when installing the library
)

install(
    TARGETS mylib-header
    EXPORT mylib-header-targets
)

# Install the headers
install(
    FILES mylib-header.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT mylib-header-targets
    NAMESPACE MyLibHeader::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/mylib-header"
)

# # If the user uses the project with add_subdirectory,
# # also provide the target with the namespace as an alias
add_library(MyLibHeader::mylib-header ALIAS mylib-header)

# Install the configuration file
install(
    FILES mylib-header-config.cmake
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/mylib"
)
