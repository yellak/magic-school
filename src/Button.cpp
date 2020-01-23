#include "Button.hpp"

Button::Button(float width, float height) : points(sf::Quads, 4)
{
    points[0].position = sf::Vector2f(0.f, 0.f);
    points[1].position = sf::Vector2f(width, 0.f);
    points[2].position = sf::Vector2f(width, height);
    points[3].position = sf::Vector2f(0.f, height);

    points[0].color = sf::Color::Blue;
    points[2].color = sf::Color::Blue;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(points, states);
}