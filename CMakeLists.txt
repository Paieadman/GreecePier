cmake_minimum_required(VERSION 3.15)

project(Greece)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -DDBG")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(BIN_NAME "GreecePier")


include_directories(
    src/items/common
    src/items/interfaces
)

set(GENERIC_SOURCE_FILES
    src/items/common/Specification.cpp
)

add_executable(
    ${BIN_NAME}
    ${GENERIC_SOURCE_FILES}
    main.cpp
    )

SET(libTQueue ON)

add_subdirectory(src)