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
    while (gameWindow->isOpen())
    {
        while (gameWindow->pollEvent(*event))
        {
            switch (event->type)
            {
            case sf::Event::Closed:
                gameWindow->close();
                break;
            
            default:
                break;
            }
        }
        
        gameWindow->clear(sf::Color::Black);
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