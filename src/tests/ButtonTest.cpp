#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.hpp"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(500, 500), "Button Test");

    Button button(100.f, 100.f, 0.2);
    Button button2(100.f, 200.f, 0.2);

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
                    sf::Vector2f mousePosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
                    if (button.getGlobalBounds().contains(mousePosition))
                    {
                        if (animationEnded)
                        {
                            animationEnded = false;
                        }
                        std::cout << "Button 1 pressed!" << std::endl;
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
                float scale;
                if (current < totalTime/2.f)
                {
                    scale = 1.f - (current / (totalTime/2.f))/2.f;
                }
                else
                {
                    scale = 0.5f + (current / totalTime) / 2.f;
                }
                button.setScale(scale, scale);
            }
        }
        
        
        window.clear(sf::Color::Black);
        window.draw(button);
        window.draw(button2);
        window.display();
    }
    
}