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
    // TODO Take this to other place other than here
    Button* button = new Button();
    auto texture = new sf::Texture();
    texture->loadFromFile("assets/textures/defaultButton.png");
    button->setTexture(*texture);

    auto font = new sf::Font();
    font->loadFromFile("assets/fonts/Ubuntu-M.ttf");
    auto text = new sf::Text();
    text->setFont(*font);
    text->setCharacterSize(20);
    text->setString("Start!");
    text->setFillColor(sf::Color::Black);
    button->setText(*text);

    sf::Vector2f newButtonPosition(gameWindow->getSize().x/2, gameWindow->getSize().y/2);
    button->setPosition(newButtonPosition);

    clock.restart();
    while (gameWindow->isOpen())
    {
        frameTime = clock.restart();
        while (gameWindow->pollEvent(*event))
        {
            switch (event->type)
            {
            case sf::Event::Closed:
                gameWindow->close();
                break;
            
            case sf::Event::MouseButtonPressed:
                if (event->mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePosition(sf::Mouse::getPosition(*gameWindow).x, sf::Mouse::getPosition(*gameWindow).y);
                    button->click(mousePosition);
                }
                break;
            
            default:
                break;
            }
        }

        button->update(frameTime);
        
        gameWindow->clear(sf::Color::Black);
        gameWindow->draw(*button);
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