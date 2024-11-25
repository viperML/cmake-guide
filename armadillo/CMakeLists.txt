cmake_minimum_required(VERSION 3.29.6)

project(armadillo VERSION 0.1 LANGUAGES C CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(armadillo SHARED armadillo.cpp)

target_include_directories(
    armadillo
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS armadillo
    EXPORT Armadillo-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    FILES armadillo.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

export(
    EXPORT Armadillo-targets
    NAMESPACE Armadillo::
    FILE Armadillo-targets.cmake
)

install(
    EXPORT Armadillo-targets
    NAMESPACE Armadillo::
    FILE Armadillo-targets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Armadillo
)


install(
    FILES Armadillo-config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Armadillo
)
