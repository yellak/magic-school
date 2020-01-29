#include "Button.hpp"

Button::Button() : Button(sf::seconds(0.1f), sf::seconds(0.002))
{
}

Button::Button(sf::Time totalAnimationTime, sf::Time switchAnimantionTime)
{
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
    if (clickAnimation != NULL)
    {
        delete clickAnimation;
    }
}

void Button::update(const sf::Time frameTime)
{
    clickAnimation->update(frameTime);
}

void Button::click(const sf::Vector2f mousePosition)
{
    if (contains(mousePosition))
    {
        if (clickAnimation->isEnded())
        {
            clickAnimation->start();
        }
    }
}

sf::FloatRect Button::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite, states);
    target.draw(text, states);
}

bool Button::contains(const sf::Vector2f& position) const
{
    return getTransform().transformRect(sprite.getGlobalBounds()).contains(position);
}

void Button::setTexture(const sf::Texture& texture)
{
    sprite.setTexture(texture);
    Util::Transform::centreOrigin(sprite);
}

void Button::setString(const sf::String& string)
{
    text.setString(string);
    Util::Transform::centreOrigin(text);
}

void Button::setCharacterSize(unsigned int size)
{
    text.setCharacterSize(size);
    Util::Transform::centreOrigin(text);
}

sf::Text Button::getText()
{
    return text;
}

void Button::setText(const sf::Text& text)
{
    this->text = text;
    Util::Transform::centreOrigin(this->text);
}

TransformAnimation* Button::getClickAnimation()
{
    return clickAnimation;
}