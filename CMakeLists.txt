cmake_minimum_required(VERSION 4.0)
project(RarCracker)

set(CMAKE_CXX_STANDARD 23)

add_executable(RarCracker src/main.cpp
        src/rar/rar_reader.cpp
        src/rar/rar_reader.h
        src/util/hex_utils.cpp
        src/util/hex_utils.h)
