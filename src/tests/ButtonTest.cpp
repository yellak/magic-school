#include <SFML/Graphics.hpp>
#include "Button.hpp"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(200, 200), "Button Test");

    Button button(40, 20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed :
                window.close();
                break;
            
            default:
                break;
            }
        }
        
        window.clear(sf::Color::Black);
        window.draw(button);
        window.display();
    }
    
}