#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Util.hpp"

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
     * @brief The text of the button.
     */
    sf::Text* text;

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
     */
    void loadSprite();

    /**
     * @brief Set the sprite origin to the middle of the button.
     */
    void setSpriteOriginToMiddle();

    /**
     * @brief Set the Text Origin To Middle.
     */
    void setTextOriginToMiddle();

public:
    /**
     * @brief Construct a new Button object.
     * The Button made has position x = 0 and y = 0.
     */
    Button();

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

    /**
     * @brief Return if the button has the position provided or not.
     * 
     * @param position The position that is going to be checked.
     * @return true If the position is inside the button.
     * @return false If it's not.
     */
    bool contains(const sf::Vector2f& position) const;

    ////////////////////////////////////////////////////////////////
    // Getters and Setters
    ////////////////////////////////////////////////////////////////

    sf::Texture* getTexture();
    void setTexture(sf::Texture*);

    sf::Text* getText();
    void setText(sf::Text*);
};

#endif