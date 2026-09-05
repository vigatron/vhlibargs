cmake_minimum_required(VERSION 3.16)
project(vhlibplatform VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/generated/version_argsparser.h"
)

add_library(vhlib_args INTERFACE)


target_sources(vhlib_args INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/argsparser.hpp
)

target_include_directories(vhlib_args INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    "${CMAKE_CURRENT_BINARY_DIR}/generated"
)
