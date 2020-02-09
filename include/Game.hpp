#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "StateMachine.hpp"
#include "MainMenu.hpp"
#include "Play.hpp"

class Game
{
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

        State* mainMenu;
        State* playing;

        /////////////////////////////////////////////////////
        // Getters and setters
        /////////////////////////////////////////////////////

        sf::RenderWindow* getGameWindow();

        sf::Event* getEvent();

        inline Scene* getScene()
        {
            return scene;
        }

        inline void setScene(Scene* scene)
        {
            this->scene = scene;
        }

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

        Scene* scene;

        StateMachine* state;
};

namespace states
{
    namespace game
    {
        State* mainMenuHandle(Game&, const sf::Event&, const sf::Vector2f&);
        State* mainMenuUpdate(Game&, const sf::Time&);

        State* playingHandle(Game&, const sf::Event&, const sf::Vector2f&);
        State* playingUpdate(Game&, const sf::Time&);
    }
}

#endif