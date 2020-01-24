#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable, public sf::Transformable
{
private:
    /**
     * @brief The texture of the button.
     */
    sf::Texture* texture;

    /**
     * @brief The sprite of the button.
     * This is basically the shape of the button.
     */
    sf::Sprite* sprite;

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

    /**
     * @brief Load the sprite of the button with the texture.
     * 
     * @param x The x position of the sprite.
     * @param y The y position of the sprite.
     * @param scale The initial scale of the sprite.
     */
    void loadSprite(float x, float y, float scale);

    /**
     * @brief Set the sprite origin to the middle of the button.
     */
    void setSpriteOriginToMiddle();

public:
    /**
     * @brief Construct a new Button object.
     * The Button made has position x = 0 and y = 0.
     * 
     * @param scale The initial scale of the button.
     */
    Button(float scale);

    /**
     * @brief Construct a new Button object.
     * 
     * @param x The x position of the button.
     * @param y The y position of the button.
     * @param scale The initial scale of the button.
     */
    Button(float x, float y, float scale);

    /**
     * @brief Return the bounds of the button.
     * 
     * @return sf::FloatRect The area that the button occupies.
     */
    sf::FloatRect getGlobalBounds();

    /**
     * @brief Destroy the Button object
     */
    ~Button();
};

#endif