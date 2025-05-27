cmake_minimum_required(VERSION 3.28)
project(Game-Pattern-Visualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    SYSTEM
)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    Source/*.cpp
)

add_executable(Game-Pattern-Visualizer ${SOURCES})

target_include_directories(Game-Pattern-Visualizer PRIVATE
    ${PROJECT_SOURCE_DIR}/Source
    ${PROJECT_SOURCE_DIR}/Patterns
)

target_link_libraries(Game-Pattern-Visualizer PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

add_custom_command(TARGET Game-Pattern-Visualizer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/Resources
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources
)