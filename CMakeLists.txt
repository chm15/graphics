cmake_minimum_required(VERSION 3.0.0)
project(game_engine VERSION 0.1.0)

include(CTest)
enable_testing()


add_subdirectory( ${PROJECT_SOURCE_DIR}/GLEW/build/cmake )
add_subdirectory( ${PROJECT_SOURCE_DIR}/GLFW )

add_executable(game_engine main.cpp)

target_include_directories(game_engine PRIVATE
    ${PROJECT_SOURCE_DIR}/GLEW/include
)

target_link_libraries(game_engine glew_s glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
