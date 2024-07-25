cmake_minimum_required(VERSION 3.5)

project(ragel_parser_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB RL_FILES "*.rl")

set(PARSER_LIBRARY_SOURCES
    custom_struct.h
    parser.h
    parser.cpp
)

add_library(parser STATIC ${PARSER_LIBRARY_SOURCES})
set_property(TARGET parser PROPERTY POSITION_INDEPENDENT_CODE ON)

add_executable(ragel_parser_example main.cpp custom_struct.h parser.h)
target_link_libraries(ragel_parser_example PRIVATE parser)
