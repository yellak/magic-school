#include "Game.hpp"

Game::Game()
{
    gameWindow = new sf::RenderWindow();
    event = new sf::Event();
    gameWindow->create(sf::VideoMode(640, 480), "Magic School");
}

Game::~Game()
{
    std::cout << "The Game is ending..." << std::endl;
    delete gameWindow;
    delete event;
}

void Game::play()
{
    Scene* scene = new scene::MainMenu(*gameWindow);

    clock.restart();
    while (gameWindow->isOpen())
    {
        frameTime = clock.restart();
        while (gameWindow->pollEvent(*event))
        {
            sf::Vector2f mousePosition(sf::Mouse::getPosition(*gameWindow).x, sf::Mouse::getPosition(*gameWindow).y);
            switch (event->type)
            {
            case sf::Event::Closed:
                gameWindow->close();
                break;
            
            default:
                scene->handleEvent(*event, mousePosition);
                break;
            }
        }

        scene->update(frameTime);
        
        gameWindow->clear();
        gameWindow->draw(*scene);
        gameWindow->display();
    }
}

sf::RenderWindow* Game::getGameWindow()
{
    return gameWindow;
}

sf::Event* Game::getEvent()
{
    return event;
}