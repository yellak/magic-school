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
     * @brief Called when we want to draw the button.
     * 
     * @param target The window where the button is going to be drawn.
     * @param states The state object that specifies the next state of the button.
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Button(float width, float height);
};

#endif