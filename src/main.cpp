#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(500, 500), "Test window");
    Game game;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                std::cout << game.getTitle() << std::endl;
                window.close();
                break;
            
            default:
                break;
            }
        }
        
        window.clear(sf::Color::Black);
        window.display();
    }
    
    return 0;
}