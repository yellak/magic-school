#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <SFML/Window/Event.hpp>
#include <functional>

/**
 * @brief Abstract class that represents a state.
 * A state defines how an object works in certain situation.
 */
class State
{
    public:
        /**
         * @brief Update method for the state.
         * 
         * @return State* Next state, if any.
         */
        virtual inline State* update(const sf::Time&)
        {
        }

        /**
         * @brief HandleEvent method for the state.
         * 
         * @return State* Next state, if any.
         */
        virtual inline State* handleEvent(const sf::Event&, const sf::Vector2f&)
        {
        }
};

#endif