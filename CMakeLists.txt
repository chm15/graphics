cmake_minimum_required(VERSION 3.0.0)
project(game_engine VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()


file(GLOB_RECURSE SOURCES src/*.cpp)

add_subdirectory( ${PROJECT_SOURCE_DIR}/GLEW/build/cmake )
add_subdirectory( ${PROJECT_SOURCE_DIR}/GLFW )

#add_executable(game_engine src/main.cpp)
add_executable(game_engine ${SOURCES})

target_include_directories(game_engine PRIVATE
    ${PROJECT_SOURCE_DIR}/GLEW/include
)

target_link_libraries(game_engine glew_s glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
