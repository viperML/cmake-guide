cmake_minimum_required(VERSION 3.28)

project(chimpanzee LANGUAGES C CXX)

find_package(armadillo REQUIRED)

add_executable(chimpanzee chimpanzee.cpp)

target_link_libraries(chimpanzee PRIVATE armadillo::armadillo)
