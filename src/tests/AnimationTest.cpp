#include <iostream>
#include "Animation.hpp"

sf::Text* loadText()
{
    auto font = new sf::Font();
    font->loadFromFile("assets/fonts/Ubuntu-M.ttf");
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

    Animation animation(sf::seconds(0.5f), sf::seconds(0.05));

    sf::Text* text = loadText();

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

        if (!animation.isEnded())
        {
            animation.setCurrent(animation.getCurrent() + frameTime);
            if (animation.getCurrent() >= animation.getTotalTime())
            {
                animation.setCurrent(sf::microseconds(0.f));
                animation.end();
                text->setPosition(0.f, 0.f);
            }
            else if (animation.getCurrent() >= animation.getSwitchTime())
            {
                text->move(0.09f, 0);
            }
        }

        window.clear(sf::Color::Black);
        window.draw(*text);
        window.display();
    }

    return 0;
}