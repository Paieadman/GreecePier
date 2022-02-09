target_include_directories(${BIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(${BIN_NAME} PUBLIC ShipGenerator.cpp)


# add_library(ShipGenerator STATIC ShipGenerator.cpp)

# target_include_directories(${BIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# target_link_libraries(${BIN_NAME} PUBLIC ShipGenerator)