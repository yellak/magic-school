#include "Game.hpp"

Game::Game()
{
    gameWindow = new sf::RenderWindow();
    event = new sf::Event();
    gameWindow->create(sf::VideoMode(640, 480), "Magic School");

    scene = new scene::MainMenu(*gameWindow);

    mainMenu = new State();
    playing = new State();
    state = new StateMachine(mainMenu);

    mainMenu->setHandleEvent([this] (auto event, auto mousePosition) {
        return states::game::mainMenuHandle(*this, event , mousePosition);
    });
    mainMenu->setUpdate([this] (auto frameTime) {
        return states::game::mainMenuUpdate(*this, frameTime);
    });

    playing->setHandleEvent([this] (auto event, auto mousePosition) {
        return states::game::playingHandle(*this, event, mousePosition);
    });

    playing->setUpdate([this] (auto frameTime) {
        return states::game::playingUpdate(*this, frameTime);
    });
}

Game::~Game()
{
    std::cout << "The Game is ending..." << std::endl;
    delete gameWindow;
    delete event;
    delete mainMenu;
    delete playing;
    delete state;
}

void Game::play()
{
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
                state->handleEvent(*event, mousePosition);
                break;
            }
        }

        state->update(frameTime);
        
        gameWindow->clear(sf::Color::White);
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