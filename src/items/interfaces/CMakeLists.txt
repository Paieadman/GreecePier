# target_include_directories(${BIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_sources(
#     ${BIN_NAME} PUBLIC
#     IShip.h
#     IShipGenerator.h
#     ICapacity.h
#     IContent.h
#     IManager.h
#     )

# add_library(interfaces INTERFACE)

# target_include_directories(interfaces INTERFACE
#     ${CMAKE_CURRENT_SOURCE_DIR}
#     ${CMAKE_CURRENT_SOURCE_DIR}/../common
#     )

# target_link_libraries(${BIN_NAME} INTERFACE interfaces)