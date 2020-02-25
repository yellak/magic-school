#include "MainMenu.hpp"
#include "Play.hpp"
#include "StateMachine.hpp"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(640, 480), "Scene Test");

    scene::MainMenu* mainMenuScene = new scene::MainMenu(window);
    scene::Play* playScene = new scene::Play();
    Scene* scene = mainMenuScene;

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
                scene->handleEvent(event, mousePosition);
                if (scene == mainMenuScene)
                {
                    if (mainMenuScene->isEnded())
                    {
                        scene = playScene;
                    }
                }
                break;
            }
        }

        scene->update(frameTime);
        
        window.clear(sf::Color::White);
        window.draw(*scene);
        window.display();
    }
}