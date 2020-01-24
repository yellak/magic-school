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
    setTextOriginToMiddle();
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
    setSpriteOriginToMiddle();
    sprite->setPosition(sprite->getOrigin());
    setOrigin(sprite->getOrigin());
    setPosition(sprite->getPosition());
}

void Button::setSpriteOriginToMiddle()
{
    sf::FloatRect localBounds = sprite->getLocalBounds();
    float origin_x = floor(localBounds.width/2.f);
    float origin_y = floor(localBounds.height/2.f);
    sprite->setOrigin(origin_x, origin_y);
}

void Button::setTextOriginToMiddle()
{
    sf::FloatRect localBounds = text->getLocalBounds();
    float origin_x = localBounds.width/2.f;
    float origin_y = localBounds.height/2.f;
    text->setOrigin(floor(origin_x),floor(origin_y));
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