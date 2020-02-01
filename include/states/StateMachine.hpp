#ifndef _STATE_MACHINE_HPP_
#define _STATE_MACHINE_HPP_

#include "State.hpp"
#include <SFML/Graphics.hpp>

/**
 * @brief Class that controls the behaviour of the object's events.
 * 
 */
class StateMachine
{
    public:
        StateMachine(State* initialState)
        {
            current = initialState;
        }

        inline void update(const sf::Time& frameTime)
        {
            next = current->update(frameTime);
            if (next != nullptr)
            {
                current = next;
            }
        }

        inline void handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition)
        {
            next = current->handleEvent(event, mousePosition);
            if (next != nullptr)
            {
                current = next;
            }
        }

        inline State* getCurrent()
        {
            return current;
        }

        inline State* getNext()
        {
            return next;
        }

    private:
        State* current;
        State* next;
};

#endif