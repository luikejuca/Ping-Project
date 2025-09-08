add_library(ping_project)

target_sources(ping_project
    PRIVATE
        icmp_message.cc
)

target_include_directories(ping_project
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
INSTALL(TARGETS ping_project DESTINATION lib)
