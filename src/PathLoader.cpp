#include <PathLoader.hpp>

std::string PathLoader::root = "../";
std::string PathLoader::assets = "assets/";
std::string PathLoader::texture = "textures/";
std::string PathLoader::font = "fonts/";

std::string PathLoader::pathBuilder(std::initializer_list<std::string> folders)
{
    std::string result;
    for (auto folder : folders)
    {
        result += folder;
    }
    return result;
}

std::string PathLoader::putExtension(std::string file, std::string extension)
{
    std::string result = std::string(file);
    if (file.find(".") == std::string::npos)
    {
        result.append(extension);
    }
    return result;
}

std::string PathLoader::toAssetsFolder()
{
    return pathBuilder({root, assets});
}

std::string PathLoader::toTexture(std::string fileName)
{
    fileName = putExtension(fileName, ".png");
    return pathBuilder({root, assets, texture, fileName});
}

std::string PathLoader::toFont(std::string fileName)
{
    return pathBuilder({root, assets, font, fileName});
}