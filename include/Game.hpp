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

        /**
         * @brief The main menu state.
         * This is the first state of the game, after it, the
         * game begins.
         */
        State* mainMenu;

        /**
         * @brief The playing state of the game.
         * At this state, the user is playing and a lot of
         * things is happening in the screen.
         */
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

        /**
         * @brief Represents the actual scene of the game.
         * The scene is related to the state of the game, so
         * if you are in the main menu state, you're also in
         * the main menu scene.
         */
        Scene* scene;

        /**
         * @brief This controls the states of the game.
         * As the state changes, the scene also changes.
         */
        StateMachine* state;
};

/**
 * @brief Namespace for general states
 * 
 */
namespace states
{
    /**
     * @brief For the states of the game.
     */
    namespace game
    {
        /**
         * @brief Handle state while in main menu method for the game.
         * Controls how the game behave when in the main menu state
         * and inside the event loop.
         * 
         * @return State* The next state of the game.
         */
        State* mainMenuHandle(Game&, const sf::Event&, const sf::Vector2f&);

        /**
         * @brief Update state while in main menu method for the game.
         * Controls how the game behave when in the main menu state
         * and after the event loop.
         * 
         * @return State* The next state of the game.
         */
        State* mainMenuUpdate(Game&, const sf::Time&);

        /**
         * @brief Handle state while playing method for the game.
         * Controls how the game behave when in the playing state
         * and inside the event loop.
         * 
         * @return State* The next state of the game.
         */
        State* playingHandle(Game&, const sf::Event&, const sf::Vector2f&);

        /**
         * @brief Update state while playing method for the game.
         * Controls how the game behave when in the playing state
         * and after the event loop.
         * 
         * @return State* The next state of the game.
         */
        State* playingUpdate(Game&, const sf::Time&);
    }
}

#endif