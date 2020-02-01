#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <SFML/Window/Event.hpp>
#include <functional>

/**
 * @brief Abstract class that represents a state.
 * 
 */
class State
{
    public:
        std::function<State*(const sf::Time&)> update;
        inline void setUpdate(std::function<State*(const sf::Time&)> update)
        {
            this->update = update;
        }

        std::function<State*(const sf::Event&, const sf::Vector2f&)> handleEvent;
        inline void setHandleEvent(std::function<State*(const sf::Event&, const sf::Vector2f&)> handleEvent)
        {
            this->handleEvent = handleEvent;
        }
};

#endif