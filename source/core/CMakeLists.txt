set(LIBRARY_NAME core)

message("------ Target: ${LIBRARY_NAME}")

file(GLOB ${LIBRARY_NAME}_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/pool/*.cpp
)

set(PUBLIC_INCLUDE_DIR 
    ${CMAKE_CURRENT_SOURCE_DIR}/pool
)

add_library(${LIBRARY_NAME} SHARED ${${LIBRARY_NAME}_SRC})
target_include_directories(${LIBRARY_NAME} PUBLIC ${PUBLIC_INCLUDE_DIR})
target_link_libraries(${LIBRARY_NAME} pthread)