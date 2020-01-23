#include <SFML/Graphics.hpp>
#include "Button.hpp"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(300, 300), "Button Test");

    Button button(20*1.96, 20);
    Button button2(100, 0, 50*1.96, 50);

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