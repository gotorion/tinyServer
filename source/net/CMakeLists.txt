set(LIBRARY_NAME net)

message("------ Target: ${LIBRARY_NAME}")

file(GLOB ${LIBRARY_NAME}_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

set(PUBLIC_INCLUDE_DIR 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(${LIBRARY_NAME} SHARED ${${LIBRARY_NAME}_SRC})
target_include_directories(${LIBRARY_NAME} PUBLIC ${PUBLIC_INCLUDE_DIR})
target_link_libraries(${LIBRARY_NAME} pthread)