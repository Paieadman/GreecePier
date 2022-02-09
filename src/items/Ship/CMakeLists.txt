# target_include_directories(${BIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_sources(${BIN_NAME} PUBLIC Ship.cpp Capacity.cpp Content.cpp)

add_library(Ship SHARED Ship.cpp Capacity.cpp Content.cpp)
# target_link_libraries(Ship interfaces)

target_include_directories(Ship PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    # ${CMAKE_CURRENT_SOURCE_DIR}/../common
    )


target_link_libraries(${BIN_NAME} PUBLIC Ship)