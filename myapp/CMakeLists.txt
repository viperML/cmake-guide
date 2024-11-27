cmake_minimum_required(VERSION 3.16)

project(myapp VERSION 0.1 LANGUAGES CXX)

add_executable(myapp myapp.cpp)


# There are 2 options:
# - Using an externally built MyLib. The user must pass explictely:
#   - The prefix path with CMAKE_PREFIX_PATH=../out
#   - The option to use it -DUSE_EXTERNAL_MYLIB=ON
# - Use it as a subdirectory

set(USE_EXTERNAL_MYLIB CACHE BOOL "Whether to use an external MyLib with find_package")

if(USE_EXTERNAL_MYLIB)
    message(STATUS "Using external MyLib")
    find_package(mylib REQUIRED)
else()
    message(STATUS "Using vendored MyLib")
    add_subdirectory(../mylib mylib)
endif()


# The modern way is to use targets, instead of _INCLUDE_DIRS or _LIBRARIES
target_link_libraries(myapp PRIVATE MyLib::mylib)

