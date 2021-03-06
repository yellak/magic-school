#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <Button.hpp>
#include <PathLoader.hpp>

sf::Texture* loadTexture()
{
    auto texture = new sf::Texture();
    texture->loadFromFile(PathLoader::toTexture("defaultButton"));
    return texture;
}

sf::Text* loadText()
{
    auto font = new sf::Font();
    font->loadFromFile(PathLoader::toFont("Ubuntu-M"));
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

    button.setTexture(*loadTexture());
    button.move(100.f, 100.f);
    button.setText(*loadText());
    sf::Time frameTime = sf::microseconds(0.f);

    sf::Clock clock;
    while (window.isOpen())
    {
        frameTime = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            sf::Vector2f mousePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            default:
                button.handleEvent(event, mousePosition);
                break;
            }
        }

        button.update(frameTime);
        
        window.clear(sf::Color::Black);
        window.draw(button);
        window.display();
    }
}