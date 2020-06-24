#ifndef _PATH_LOADER_HPP_
#define _PATH_LOADER_HPP_

#include <string>
#include <initializer_list>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

/**
 * @brief Load the path to an object.
 */
class PathLoader
{
public:
    /**
     * @brief Load the path to a specified image.
     * 
     * @return std::string The path created.
     */
    static std::string toTexture(std::string);

    /**
     * @brief Load the path to a specified font.
     * 
     * @return std::string 
     */
    static std::string toFont(std::string);

    /**
     * @brief Load the path to the assets folder.
     * 
     * @return std::string The path created.
     */
    static std::string toAssetsFolder();

    /**
     * @brief Get the Root directory of the project.
     * 
     * @return std::string The root directory.
     */
    static fs::path getRoot();

private:
    /**
     * @brief The root directory.
     */
    static fs::path root;

    /**
     * @brief The assets folder name.
     * "assets" by default.
     */
    static fs::path assets;

    /**
     * @brief The textures folder name.
     * "textures" by default.
     */
    static fs::path texture;

    /**
     * @brief The fonts folder name.
     * "fonts" by default.
     */
    static fs::path font;
};

#endif // _PATH_LOADER_HPP_