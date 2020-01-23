#include <SFML/Graphics.hpp>
#include "Button.hpp"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(500, 500), "Button Test");

    Button button(100.f, 100.f, 0.2);
    Button button2(100.f, 200.f, 0.2);

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
        window.draw(button2);
        window.display();
    }
    
}