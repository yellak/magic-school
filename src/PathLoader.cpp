#include <PathLoader.hpp>

fs::path PathLoader::root = "";
fs::path PathLoader::assets = "assets";
fs::path PathLoader::texture = "textures";
fs::path PathLoader::font = "fonts";

fs::path PathLoader::getRoot()
{
    root = fs::current_path();
    if (!fs::exists(root/assets))
    {
        root.remove_filename();
    }
    return root;
}

std::string PathLoader::toAssetsFolder()
{
    return getRoot()/assets;
}

std::string PathLoader::toTexture(std::string fileName)
{
    auto path = toAssetsFolder()/texture/fs::path(fileName);
    if (!path.has_extension())
    {
        path.replace_extension(".png");
    }
    return path;
}

std::string PathLoader::toFont(std::string fileName)
{
    auto path = toAssetsFolder()/font/fs::path(fileName);
    if (!path.has_extension())
    {
        path.replace_extension(".ttf");
    }
    return path;
}