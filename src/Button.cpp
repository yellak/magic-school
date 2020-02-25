#include "Button.hpp"

Button::Button() : Button(sf::seconds(0.1f), sf::seconds(0.002))
{
}

Button::Button(sf::Time totalAnimationTime, sf::Time switchAnimantionTime):
clickAnimation(totalAnimationTime, switchAnimantionTime)
{
    auto endMethod = [this] () {
        setScale(1.f, 1.f);
    };

    auto switchMethod = [this] () {
        float normalized = clickAnimation.getCurrent()/clickAnimation.getTotalTime();
        float scale = pow(normalized/2 - 0.3, 2) + 0.9;
        setScale(scale, scale);
    };

    clickAnimation.setSwitchMethod(switchMethod);
    clickAnimation.setEndMethod(endMethod);

    standBy = new states::button::StandBy(this);
    clicking = new states::button::Clicking(this);
    state = new StateMachine(standBy);
}

Button::~Button()
{
    if (standBy != nullptr)
    {
        delete standBy;
    }
    if (clicking != nullptr)
    {
        delete clicking;
    }
}

void Button::update(const sf::Time& frameTime)
{
    state->update(frameTime);
}

void Button::handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition)
{
    state->handleEvent(event, mousePosition);
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

sf::Text& Button::getText()
{
    return text;
}

void Button::setText(const sf::Text& text)
{
    this->text = text;
    Util::Transform::centreOrigin(this->text);
}

TransformAnimation& Button::getClickAnimation()
{
    return clickAnimation;
}

states::button::StandBy::StandBy(Button* bt):
button(bt)
{
}

State* states::button::StandBy::update(const sf::Time& frameTime)
{
    return nullptr;
}

State* states::button::StandBy::handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition)
{
    State* next = nullptr;
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (button->contains(mousePosition))
            {
                if (button->getClickAnimation().isEnded())
                {
                    button->getClickAnimation().start();
                    next = button->clicking;
                }
            }
        }
        break;
    
    default:
        break;
    }
    return next;
}

states::button::Clicking::Clicking(Button* bt):
button(bt)
{
}

State* states::button::Clicking::update(const sf::Time& frameTime)
{
    button->getClickAnimation().update(frameTime);
    State* next = nullptr;
    if (button->getClickAnimation().isEnded())
    {
        next = button->standBy;
    }
    return next;
}

State* states::button::Clicking::handleEvent(const sf::Event&, const sf::Vector2f&)
{
    State* next = nullptr;
    if (button->getClickAnimation().isEnded())
    {
        next = button->standBy;
    }
    return next;
}