#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Button.hpp"

sf::Texture* loadTexture()
{
    auto texture = new sf::Texture();
    texture->loadFromFile("assets/textures/defaultButton.png");
    return texture;
}

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
    window.create(sf::VideoMode(500, 500), "Button Test");

    Button button;

    button.setTexture(loadTexture());
    button.move(100.f, 100.f);
    button.setText(loadText());

    sf::Time current = sf::microseconds(0.f);
    sf::Time totalTime = sf::microseconds(100000.f);
    sf::Time switchTime = sf::microseconds(500.f);
    sf::Time frameTime = sf::microseconds(0.f);
    bool animationEnded = true;

    sf::Clock clock;
    while (window.isOpen())
    {
        frameTime = sf::microseconds(clock.restart().asMicroseconds());
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    if (button.contains(mousePosition))
                    {
                        if (animationEnded)
                        {
                            animationEnded = false;
                        }
                        std::cout << "Button 1 pressed" << std::endl;
                    }
                }
                break;
            
            default:
                break;
            }
        }

        if (!animationEnded)
        {
            current += frameTime;
            if (current >= totalTime)
            {
                current = sf::microseconds(0.f);
                button.setScale(1.f, 1.f);
                animationEnded = true;
            }
            else if (current >= switchTime)
            {
                float normalized = current/totalTime;
                float scale = pow(normalized/2 - 0.3, 2) + 0.9;
                button.setScale(scale, scale);
            }
        }
        
        window.clear(sf::Color::Black);
        window.draw(button);
        window.display();
    }
    
}