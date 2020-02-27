#ifndef _STATE_MACHINE_HPP_
#define _STATE_MACHINE_HPP_

#include <State.hpp>
#include <SFML/Graphics.hpp>

/**
 * @brief Class that controls the behaviour of the object's events.
 * Controls the behaviour of an object and how it switch states.
 */
class StateMachine
{
    public:
        StateMachine(State* initialState)
        {
            current = initialState;
        }

        /**
         * @brief Update method for the actual state.
         * This method must contain all the update logic that depends only on
         * the frameTime of the main loop and the switch state logic that depends
         * on that logic.
         * 
         * @param frameTime The time took by the main loop.
         */
        inline void update(const sf::Time &frameTime)
        {
            next = current->update(frameTime);
            if (next != nullptr)
            {
                current = next;
            }
        }

        /**
         * @brief HandleEvent method for the actual state.
         * 
         * @param event The event caught.
         * @param mousePosition The actual position of the mouse.
         */
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