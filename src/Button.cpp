#include "Button.hpp"

Button::Button(float scale) : Button(0.f, 0.f, scale)
{
}

Button::Button(float x, float y, float scale)
{
    loadTexture();
    loadSprite(x, y, scale);
}

Button::~Button()
{
    delete texture;
    delete sprite;
}

void Button::loadTexture()
{
    texture = new sf::Texture();
    texture->loadFromFile("assets/textures/defaultButton.png");
}

void Button::loadSprite(float x, float y, float scale)
{
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);

    sf::FloatRect globalBounds = sprite->getGlobalBounds();
    float origin_x = globalBounds.left + globalBounds.width/2;
    float origin_y = globalBounds.top + globalBounds.height/2;
    sprite->setOrigin(origin_x, origin_y);

    sprite->setPosition(x, y);
    sprite->setScale(scale, scale);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*sprite, states);
}