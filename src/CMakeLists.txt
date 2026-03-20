cmake_minimum_required(VERSION 3.23)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/consumer)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/producer)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/main.c
)
