cmake_minimum_required(VERSION 3.29.6)

project(myproject VERSION 0.1 LANGUAGES C CXX)

include(GNUInstallDirs)

add_library(mylib SHARED mylib.cpp)

target_include_directories(
    mylib
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS mylib
    EXPORT mylib-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    FILES mylib.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT mylib-targets
    NAMESPACE MyLib::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/mylib"
)

install(
    FILES mylib-config.cmake
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/mylib"
)
