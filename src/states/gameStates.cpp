#include "Game.hpp"

namespace states
{
    namespace game
    {
        State* nextFromMainMenu(Game& game)
        {
            State* next = nullptr;
            if (game.getScene()->isEnded())
            {
                delete game.getScene();
                game.setScene(new scene::Play());
                next = game.playing;
            }
            return next;
        }

        State* mainMenuHandle(Game& game, const sf::Event& event, const sf::Vector2f& mousePosition)
        {
            game.getScene()->handleEvent(event, mousePosition);
            return nextFromMainMenu(game);
        }

        State* mainMenuUpdate(Game& game, const sf::Time& frameTime)
        {
            game.getScene()->update(frameTime);
            return nextFromMainMenu(game);
        }

        State* nextFromPlaying(Game& game)
        {
            State* next = nullptr;
            if (game.getScene()->isEnded())
            {
                delete game.getScene();
                game.setScene(new scene::MainMenu(*game.getGameWindow()));
                next = game.mainMenu;
            }
            return next;
        }

        State* playingHandle(Game& game, const sf::Event& event, const sf::Vector2f& mousePosition)
        {
            game.getScene()->handleEvent(event, mousePosition);
            return nextFromPlaying(game);
        }

        State* playingUpdate(Game& game, const sf::Time& frameTime)
        {
            game.getScene()->update(frameTime);
            return nextFromPlaying(game);
        }
    }
}