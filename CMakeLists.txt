cmake_minimum_required(VERSION 3.22)

# Setup project
project(learncpp)
add_executable(${PROJECT_NAME})

# Add key executable block
file(GLOB_RECURSE src_files ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
target_sources(${PROJECT_NAME} PUBLIC ${src_files})

# Add key include paths
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/include
)

# Compilation definition information
target_compile_definitions(${PROJECT_NAME} PUBLIC
    WIN32
    _DEBUG
    CONSOLE
)

# Compiler options
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -std=c++11
)
