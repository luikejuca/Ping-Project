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
    gtest
    pthread
    )

INSTALL(TARGETS ping_project DESTINATION lib)
