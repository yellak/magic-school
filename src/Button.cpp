#include "Button.hpp"

Button::Button() : Button(0.f, 0.f)
{
}

Button::Button(float x, float y)
{
    loadTexture();
    loadSprite();

    textFont = new sf::Font();
    textFont->loadFromFile("assets/fonts/Ubuntu-M.ttf");
    text = new sf::Text();
    text->setFont(*textFont);
    text->setCharacterSize(20);
    text->setString(L"Kálley");
    text->setFillColor(sf::Color::Red);
    Util::Transform::centreOrigin(*text);
    text->setPosition(sprite->getPosition());
    move(x, y);
}

Button::~Button()
{
    delete texture;
    delete sprite;
    delete text;
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
    Util::Transform::centreOrigin(*sprite);
    sprite->setPosition(sprite->getOrigin());
    setOrigin(sprite->getOrigin());
    setPosition(sprite->getPosition());
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

void Button::update()
{
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
}

sf::Text* Button::getText()
{
    return text;
}

void Button::setText(sf::Text* text)
{
    this->text = text;
}