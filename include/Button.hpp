#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
private:
    /**
     * @brief The points that make the button.
     */
    sf::VertexArray points;

    /**
     * @brief The texture of the button.
     */
    sf::Texture* texture;

    /**
     * @brief Called when we want to draw the button.
     * 
     * @param target The window where the button is going to be drawn.
     * @param states The state object that specifies the next state of the button.
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * @brief Load the texture of the button.
     */
    void loadTexture();

public:
    /**
     * @brief Construct a new Button object.
     * The object dreated by this funtion has a position with values
     * x = 0 and y = 0.
     * 
     * @param width The width of the button.
     * @param height The height of the button.
     */
    Button(float width, float height);

    /**
     * @brief Construct a new Button object.
     * 
     * @param x The x position of the button.
     * @param y The y position of the button.
     * @param width The width of the button.
     * @param height The height of the button.
     */
    Button(float x, float y, float width, float height);

    /**
     * @brief Destroy the Button object
     */
    ~Button();
};

#endif