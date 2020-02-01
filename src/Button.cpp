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

    standBy = new State();
    standBy->setHandleEvent([this] (const sf::Event& event, const sf::Vector2f& mousePosition) {
        return states::button::standByHandle(*this, event, mousePosition);
    });
    standBy->setUpdate([this] (const sf::Time& frameTime) {
        return states::button::standByUpdate(*this, frameTime);
    });

    clicking = new State();
    clicking->setHandleEvent([this] (const sf::Event& event, const sf::Vector2f& mousePosition) {
        return states::button::clickingHandle(*this, event, mousePosition);
    });
    clicking->setUpdate([this] (const sf::Time& frameTime) {
        return states::button::clickingUpdate(*this, frameTime);
    });

    current = standBy;
    next = nullptr;
}

Button::~Button()
{
    if (clickAnimation != NULL)
    {
        delete clickAnimation;
    }
}

void Button::update(const sf::Time& frameTime)
{
    next = current->update(frameTime);
    if (next != nullptr)
    {
        current = next;
    }
}

void Button::handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition)
{
    next = current->handleEvent(event, mousePosition);
    if (next != nullptr)
    {
        current = next;
    }
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

State* states::button::standByHandle(Button& button, const sf::Event& event, const sf::Vector2f& mousePosition)
{
    State* next = nullptr;
    if (button.contains(mousePosition))
    {
        if (button.getClickAnimation()->isEnded())
        {
            button.getClickAnimation()->start();
            next = button.clicking;
            std::cout << "Button click!" << std::endl;
        }
    }
    return next;
}

State* states::button::clickingHandle(Button& button, const sf::Event& event, const sf::Vector2f& mousePosition)
{
    State* next = nullptr;
    if (button.getClickAnimation()->isEnded())
    {
        next = button.standBy;
    }
    return next;
}

State* states::button::standByUpdate(Button& button, const sf::Time& frameTime)
{
    return nullptr;
}

State* states::button::clickingUpdate(Button& button, const sf::Time& frameTime)
{
    button.getClickAnimation()->update(frameTime);
    State* next = nullptr;
    if (button.getClickAnimation()->isEnded())
    {
        next = button.standBy;
    }
    return next;
}