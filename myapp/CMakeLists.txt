cmake_minimum_required(VERSION 3.28)

project(myapp LANGUAGES C CXX)

find_package(mylib REQUIRED)

add_executable(myapp myapp.cpp)

target_link_libraries(myapp PRIVATE MyLib::mylib)
