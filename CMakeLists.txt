cmake_minimum_required(VERSION 3.7)
project(bsq)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        includes/utils.h
        srcs/main.c)

add_executable(bsq ${SOURCE_FILES})