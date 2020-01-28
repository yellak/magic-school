cmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME "Magic-School")

project("${PROJECT_NAME}" VERSION 0.1.0)

include_directories(include)

include(CTest)
enable_testing()

set(SFML_LIBRARIES "sfml-graphics" "sfml-window" "sfml-system")

set(MAIN_SOURCES "src/main.cpp" "src/Game.cpp" "src/Button.cpp" "src/TransformAnimation.cpp" "src/Animation.cpp")

add_executable("${PROJECT_NAME}" "${MAIN_SOURCES}")
target_link_libraries("${PROJECT_NAME}" "${SFML_LIBRARIES}")

add_executable(ButtonTest "src/tests/ButtonTest.cpp" "src/Button.cpp" "src/TransformAnimation.cpp" "src/Animation.cpp")
target_link_libraries(ButtonTest "${SFML_LIBRARIES}")

add_executable(AnimationTest "src/tests/AnimationTest.cpp" "src/Animation.cpp" "src/TransformAnimation.cpp")
target_link_libraries(AnimationTest "${SFML_LIBRARIES}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
