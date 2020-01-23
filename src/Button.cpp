#include "Button.hpp"

Button::Button(float width, float height) : Button(0.f, 0.f, width, height)
{
}

Button::Button(float x, float y, float width, float height) : points(sf::Quads, 4)
{
    points[0].position = sf::Vector2f(x, y);
    points[1].position = sf::Vector2f(x + width, y);
    points[2].position = sf::Vector2f(x + width, y + height);
    points[3].position = sf::Vector2f(x, y + height);

    loadTexture();
}

Button::~Button()
{
    delete texture;
}

void Button::loadTexture()
{
    texture = new sf::Texture();
    texture->loadFromFile("assets/textures/defaultButton.png");
    points[0].texCoords = sf::Vector2f(0.f, 0.f);
    points[1].texCoords = sf::Vector2f(599.f, 0.f);
    points[2].texCoords = sf::Vector2f(599.f, 305.f);
    points[3].texCoords = sf::Vector2f(0.f, 305.f);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.texture = texture;
    states.transform *= getTransform();
    target.draw(points, states);
}