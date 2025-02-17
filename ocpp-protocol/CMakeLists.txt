cmake_minimum_required(VERSION 3.20.0)

# set(CMAKE_CXX_COMPILER "C:/MinGW/bin")
# set(CMAKE_C_COMPILER "C:/MinGW/bin")
# set CC=gcc

set(CMAKE_C_STANDARD 11)

project(ocpp_protocol C)

add_executable(ocpp_driver
        src/ocpp_driver.c
        src/ocpp.h
        src/ocpp.c
        lib/cJSON.c
        lib/cJSON.h
)

# set the output folder where the program will be created 
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

target_compile_features(ocpp_driver PRIVATE )
target_compile_options(ocpp_driver PRIVATE -g -Wall -Wextra -Wpedantic)

