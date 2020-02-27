#include <iostream>
#include "Animation.hpp"
#include "TransformAnimation.hpp"

sf::Text* loadText()
{
    auto font = new sf::Font();
    font->loadFromFile("../assets/fonts/Ubuntu-M.ttf");
    auto text = new sf::Text();
    text->setFont(*font);
    text->setCharacterSize(20);
    text->setString(L"Kálley");
    text->setFillColor(sf::Color::Red);
    return text;
}

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(500, 500), "Animation Test");

    sf::Text* text = loadText();
    TransformAnimation animation(sf::seconds(0.5f), sf::seconds(0.05f));

    // Config of the animation
    auto endMethod = [&] () {
        text->setPosition(0.f, 0.f);
    };

    auto switchMethod = [&] () {
        text->move(0.09f, 0);
    };

    animation.setSwitchMethod(switchMethod);
    animation.setEndMethod(endMethod);

    sf::Time frameTime = sf::microseconds(0.f);
    sf::Clock frameClock;
    while (window.isOpen())
    {
        frameTime = frameClock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::TextEntered:
                if (sf::String(event.text.unicode) == sf::String("d"))
                {
                    if (animation.isEnded())
                    {
                        animation.start();
                    }
                }
                break;
            
            default:
                break;
            }
        }

        animation.update(frameTime);

        window.clear(sf::Color::Black);
        window.draw(*text);
        window.display();
    }

    return 0;
}