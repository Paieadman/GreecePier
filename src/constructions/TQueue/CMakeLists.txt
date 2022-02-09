target_include_directories(${BIN_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_sources(${BIN_NAME} PUBLIC TQueue.cpp)
target_sources(
   ${BIN_NAME} PUBLIC TQueue.h TQueue.tpp)

# option(libTQueue "my template queue library" ON)

# add_library(libtqueue STATIC TQueue.h TQueue.tpp)

# target_include_directories(libtqueue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories(${BIN_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# if(libTQueue)
# target_link_libraries(
#     ${BIN_NAME}
#     libtqueue
# )
# else()
#     message("libTQueue is switched off")
# endif()