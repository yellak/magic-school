cmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME "Magic-School")

project("${PROJECT_NAME}" VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SOURCES "src/*.cpp")

add_executable("${PROJECT_NAME}" "${SOURCES}")
target_link_libraries("${PROJECT_NAME}" sfml-graphics sfml-window sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
