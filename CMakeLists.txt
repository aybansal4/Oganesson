cmake_minimum_required(VERSION 3.10)
project(Oganesson)

find_package(Boost 1.70 REQUIRED COMPONENTS filesystem system)

add_executable(my_program main.cpp)

target_link_libraries(my_program PRIVATE Boost::filesystem Boost::system)
