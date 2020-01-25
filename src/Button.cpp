#include "Button.hpp"

Button::Button()
{
    sprite = new sf::Sprite();
    loadSprite();
}

Button::~Button()
{
    delete sprite;
}

void Button::loadSprite()
{
    Util::Transform::centreOrigin(*sprite);
    sprite->setPosition(sprite->getOrigin());
    setPosition(sprite->getPosition());
    setOrigin(sprite->getOrigin());
}

sf::FloatRect Button::getGlobalBounds()
{
    return sprite->getGlobalBounds();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(*sprite, states);
    if (text != NULL)
    {
        target.draw(*text, states);
    }
}

bool Button::contains(const sf::Vector2f& position) const
{
    return getTransform().transformRect(sprite->getGlobalBounds()).contains(position);
}

sf::Texture* Button::getTexture()
{
    return texture;
}

void Button::setTexture(sf::Texture* texture)
{
    this->texture = texture;
    sprite->setTexture(*texture);
    loadSprite();
}

sf::Text* Button::getText()
{
    return text;
}

void Button::setText(sf::Text* text)
{
    this->text = text;
    Util::Transform::centreOrigin(*text);
    text->setPosition(sprite->getPosition());
}