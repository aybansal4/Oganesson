cmake_minimum_required(VERSION 3.14)
project(Oganesson-cli)

include(FetchContent)

set(BOOST_ENABLE_CMAKE ON CACHE INTERNAL "")
set(BOOST_BUILD_TESTS OFF CACHE INTERNAL "")
set(BOOST_BUILD_EXAMPLES OFF CACHE INTERNAL "")


FetchContent_Declare(
    Boost
    URL https://github.com
    URL_HASH SHA256=29c7d4f4ac36ad853b6765d03571ea60d90286775df026b4efd9f3281131972b
)

FetchContent_MakeAvailable(Boost)

add_executable(my_app main.cpp)
add_executable(my_app cmds.h)

target_link_libraries(
    Boost::headers
    Boost::filesystem
    Boost::process
)