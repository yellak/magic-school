#include "Button.hpp"

Button::Button()
{
    text = NULL;
    sprite = new sf::Sprite();
    loadSprite();

    click = new TransformAnimation(sf::seconds(0.3f), sf::seconds(0.002));
    auto endMethod = [this] () {
        setScale(1.f, 1.f);
    };

    auto switchMethod = [this] () {
        float normalized = click->getCurrent()/click->getTotalTime();
        float scale = pow(normalized/2 - 0.3, 2) + 0.9;
        setScale(scale, scale);
    };

    click->setSwitchMethod(switchMethod);
    click->setEndMethod(endMethod);
}

Button::~Button()
{
    if (sprite != NULL)
    {
        delete sprite;
    }
    if (click != NULL)
    {
        delete click;
    }
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

TransformAnimation* Button::getClickAnimation()
{
    return click;
}