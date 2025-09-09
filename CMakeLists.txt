cmake_minimum_required(VERSION 3.12)
project(ping-project)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Subdirectories
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)
