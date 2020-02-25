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
        virtual inline State* update(const sf::Time&)
        {
        }

        virtual inline State* handleEvent(const sf::Event&, const sf::Vector2f&)
        {
        }
};

#endif