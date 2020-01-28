#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.hpp"

class Game
{
private:

    /**
     * @brief The window where the whole game is located.
     */
    sf::RenderWindow* gameWindow;

    /**
     * @brief The event object of the whole game.
     */
    sf::Event* event;

    /**
     * @brief The clock that will control the whole aplication.
     */
    sf::Clock clock;

    /**
     * @brief The time that the main loop takes to be excuted.
     */
    sf::Time frameTime;

public:

    /**
     * @brief Construct a new Game object.
     */
    Game();

    /**
     * @brief Destroy the Game object.
     */
    ~Game();

    /**
     * @brief The main method of the game.
     * This method has the main loop of the game.
     */
    void play();

    /////////////////////////////////////////////////////
    // Getters and setters
    /////////////////////////////////////////////////////

    sf::RenderWindow* getGameWindow();

    sf::Event* getEvent();
};