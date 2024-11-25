cmake_minimum_required(VERSION 3.16)

project(myapp LANGUAGES C CXX)

add_executable(myapp myapp.cpp)

# Look for mylib-config.cmake in the CMAKE_PREFIX_PATH or /usr,
# and load the namespaced targets
find_package(mylib REQUIRED)

# The modern way is to use targets, instead of _INCLUDE_DIRS or _LIBRARIES
target_link_libraries(myapp PRIVATE MyLib::mylib)

