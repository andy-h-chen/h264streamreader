# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name

project(h264streamreader CXX)

set(PROJECT_SOURCE_DIR src)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

#set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(base ${PROJECT_SOURCE_DIR}/base/build_config.h
                 ${PROJECT_SOURCE_DIR}/base/macros.h
                 ${PROJECT_SOURCE_DIR}/base/atomicops.h
                 ${PROJECT_SOURCE_DIR}/base/atomicops_internals_portable.h
                 ${PROJECT_SOURCE_DIR}/base/atomic_ref_count.h
                 ${PROJECT_SOURCE_DIR}/base/ref_counted.cc
                 ${PROJECT_SOURCE_DIR}/base/ref_counted.h
                 ${PROJECT_SOURCE_DIR}/base/stl_util.h)

add_executable(h264streamreader ${PROJECT_SOURCE_DIR}/h264_stream_reader.cc
                                ${PROJECT_SOURCE_DIR}/h264_bit_reader.cc
                                ${PROJECT_SOURCE_DIR}/h264_bit_reader.h
                                ${PROJECT_SOURCE_DIR}/h264_parser.cc
                                ${PROJECT_SOURCE_DIR}/h264_parser.h
                                ${PROJECT_SOURCE_DIR}/h264_dpb.cc
                                ${PROJECT_SOURCE_DIR}/h264_dpb.h
                                ${PROJECT_SOURCE_DIR}/h264_decoder.cc
                                ${PROJECT_SOURCE_DIR}/h264_decoder.h)
