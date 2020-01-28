#include "Button.hpp"

Button::Button() : Button(sf::seconds(0.1f), sf::seconds(0.002))
{
}

Button::Button(sf::Time totalAnimationTime, sf::Time switchAnimantionTime)
{
    text = NULL;
    sprite = new sf::Sprite();
    loadSprite();

    clickAnimation = new TransformAnimation(totalAnimationTime, switchAnimantionTime);
    auto endMethod = [this] () {
        setScale(1.f, 1.f);
    };

    auto switchMethod = [this] () {
        float normalized = clickAnimation->getCurrent()/clickAnimation->getTotalTime();
        float scale = pow(normalized/2 - 0.3, 2) + 0.9;
        setScale(scale, scale);
    };

    clickAnimation->setSwitchMethod(switchMethod);
    clickAnimation->setEndMethod(endMethod);
}

Button::~Button()
{
    if (sprite != NULL)
    {
        delete sprite;
    }
    if (clickAnimation != NULL)
    {
        delete clickAnimation;
    }
}

void Button::update(sf::Time frameTime)
{
    clickAnimation->update(frameTime);
}

void Button::click(sf::Vector2f mousePosition)
{
    if (contains(mousePosition))
    {
        if (clickAnimation->isEnded())
        {
            clickAnimation->start();
        }
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
    return clickAnimation;
}