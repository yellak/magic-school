#ifndef _PATH_LOADER_HPP_
#define _PATH_LOADER_HPP_

#include <string>
#include <initializer_list>

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
     * @brief Put an extension to the file name.
     * Puts the extension in the file name if it does not have any,
     * if it does, the method does not put the extension.
     * 
     * @param file The file name.
     * @param extension The extension to put.
     * @return std::string The file name with the extension.
     */
    static std::string putExtension(std::string file, std::string extension);

    /**
     * @brief Load the path to the assets folder.
     * 
     * @return std::string The path created.
     */
    static std::string toAssetsFolder();

private:
    /**
     * @brief Concatenate a list of strings.
     * 
     * @param folders The List of strings.
     * @return std::string The path created.
     */
    static std::string pathBuilder(std::initializer_list<std::string> folders);

    /**
     * @brief The root directory.
     * "../" by default
     */
    static std::string root;

    /**
     * @brief The assets folder name.
     * "assets/" by default.
     */
    static std::string assets;

    /**
     * @brief The textures folder name.
     * "textures/" by default.
     */
    static std::string texture;

    /**
     * @brief The fonts folder name.
     * "fonts/" by default.
     */
    static std::string font;
};

#endif // _PATH_LOADER_HPP_