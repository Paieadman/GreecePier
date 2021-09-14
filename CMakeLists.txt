cmake_minimum_required(VERSION 3.20)

project(Greece)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(BIN_NAME "GreecePier")

add_executable(
    ${BIN_NAME}
    main.cpp
    )

add_subdirectory(src)