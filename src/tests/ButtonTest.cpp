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
    //button.setText(loadText());
    sf::Time frameTime = sf::microseconds(0.f);

    sf::Clock clock;
    while (window.isOpen())
    {
        frameTime = clock.restart();
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
                        if (button.getClickAnimation()->isEnded())
                        {
                            button.getClickAnimation()->start();
                        }
                        std::cout << "Button 1 pressed" << std::endl;
                    }
                }
                break;
            
            default:
                break;
            }
        }

        button.getClickAnimation()->update(frameTime);
        
        window.clear(sf::Color::Black);
        window.draw(button);
        window.display();
    }
    
}