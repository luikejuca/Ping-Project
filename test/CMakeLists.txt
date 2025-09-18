cmake_minimum_required(VERSION 3.14)
project(ping_project_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    icmp_test
    icmp_test.cc
)

target_link_libraries(icmp_test
    PRIVATE
    ping_project 
    GTest::gtest_main
)

target_include_directories(icmp_test
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)
include(GoogleTest)
gtest_discover_tests(icmp_test)
