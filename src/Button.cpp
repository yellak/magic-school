#include "Button.hpp"

Button::Button() : Button(0.f, 0.f)
{
}

Button::Button(float x, float y)
{
    loadTexture();
    loadSprite();
    move(x, y);
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

void Button::loadSprite()
{
    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    setSpriteOriginToMiddle();
    sprite->setPosition(sprite->getOrigin());
    setOrigin(sprite->getOrigin());
    setPosition(sprite->getPosition());
}

void Button::setSpriteOriginToMiddle()
{
    sf::FloatRect globalBounds = sprite->getGlobalBounds();
    float origin_x = globalBounds.left + globalBounds.width/2;
    float origin_y = globalBounds.top + globalBounds.height/2;
    sprite->setOrigin(origin_x, origin_y);
}

sf::FloatRect Button::getGlobalBounds()
{
    return sprite->getGlobalBounds();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*sprite, states);
}

void Button::update()
{
}

bool Button::contains(const sf::Vector2f& position) const
{
    return getTransform().transformRect(sprite->getGlobalBounds()).contains(position);
}