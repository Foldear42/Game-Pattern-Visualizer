cmake_minimum_required(VERSION 3.28)
project(Game-Pattern-Visualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_TEST_SUITE OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    SYSTEM
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    Game-Pattern-Visualizer/Source/*.cpp
)

add_executable(Game-Pattern-Visualizer ${SOURCES})

target_include_directories(Game-Pattern-Visualizer PRIVATE
    ${PROJECT_SOURCE_DIR}/Game-Pattern-Visualizer/Source
    ${PROJECT_SOURCE_DIR}/Game-Pattern-Visualizer/Patterns
)

target_link_libraries(Game-Pattern-Visualizer PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
    nlohmann_json::nlohmann_json
)

add_custom_command(TARGET Game-Pattern-Visualizer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/Game-Pattern-Visualizer/Resources
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Game-Pattern-Visualizer/Resources
)

target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/Game-Pattern-Visualizer/Resources/")
