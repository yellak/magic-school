#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <SFML/Window/Event.hpp>
#include <functional>

/**
 * @brief Abstract class that represents a state.
 */
class State
{
    public:
        /**
         * @brief Update method for the state.
         * This method is called before the cleaning of the window
         * and after the event handling loop.
         */
        std::function<State*(const sf::Time&)> update;
        inline void setUpdate(std::function<State*(const sf::Time&)> update)
        {
            this->update = update;
        }

        /**
         * @brief HandleEvent method for the state.
         * This method is called inside the hadle event loop.
         */
        std::function<State*(const sf::Event&, const sf::Vector2f&)> handleEvent;
        inline void setHandleEvent(std::function<State*(const sf::Event&, const sf::Vector2f&)> handleEvent)
        {
            this->handleEvent = handleEvent;
        }
};

#endif