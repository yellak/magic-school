cmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME "Magic-School")

project("${PROJECT_NAME}" VERSION 0.1.0)

include_directories("include" "include/states" "include/scenes")

include(CTest)
enable_testing()

set(SOURCES "src/Button.cpp" "src/TransformAnimation.cpp" "src/Animation.cpp"
            "src/scenes/MainMenu.cpp" "src/scenes/Play.cpp")

set(SFML_LIBRARIES "sfml-graphics" "sfml-window" "sfml-system")

set(MAIN_SOURCES "src/main.cpp" "src/Game.cpp" "src/states/gameStates.cpp" "${SOURCES}")

set(BUTTON_TESTS_SRC "src/tests/ButtonTest.cpp" "${SOURCES}")

set(SCENE_TESTS_SRC "src/tests/SceneTest.cpp" "${SOURCES}")

add_executable("${PROJECT_NAME}" "${MAIN_SOURCES}")
target_link_libraries("${PROJECT_NAME}" "${SFML_LIBRARIES}")

#add_executable(ButtonTest "${BUTTON_TESTS_SRC}")
#target_link_libraries(ButtonTest "${SFML_LIBRARIES}")

#add_executable(AnimationTest "src/tests/AnimationTest.cpp" "${SOURCES}")
#target_link_libraries(AnimationTest "${SFML_LIBRARIES}")

add_executable(SceneTest "${SCENE_TESTS_SRC}")
target_link_libraries(SceneTest "${SFML_LIBRARIES}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
