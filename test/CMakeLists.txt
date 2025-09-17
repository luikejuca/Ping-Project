add_executable(icmp_test)

target_sources(icmp_test
    PRIVATE
        icmp_test.cc
)

target_include_directories(icmp_test
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(icmp_test
    PRIVATE 
    ping_project
    GTest::gtest_main
    GTest::gmock_main
    )

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
