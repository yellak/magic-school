#include <PathLoader.hpp>
#include <iostream>

int errors = 0;

template <class T>
void print(T expected, T gotten)
{
    std::cout << "EXP: " + expected + " RES: " + gotten << std::endl;
}

template <class T>
void assertEquals(T first, T second)
{
    if (first != second)
    {
        print(first, second);
        errors++;
    }
}

int main()
{

    std::string result = PathLoader::toTexture("mainMenuBackground.png");
    assertEquals(std::string("../assets/textures/mainMenuBackground.png"), result);

    result = PathLoader::toTexture("mainMenuBackground");
    assertEquals(std::string("../assets/textures/mainMenuBackground.png"), result);

    result = PathLoader::toAssetsFolder();
    assertEquals(std::string("../assets/"), result);

    result = PathLoader::toFont("Ubuntu-M.ttf");
    assertEquals(std::string("../assets/fonts/Ubuntu-M.ttf"), result);

    return errors;
}