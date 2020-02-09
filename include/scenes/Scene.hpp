#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

/**
 * @brief Represents whats is shown in the screen.
 * This class often represents all that's shown in the screen, for
 * example, in the main menu scene you can have some buttons
 * like the play button and the options button, and/or a sprite
 * and a texture for the background. Sometimes there'll be a scene
 * inside another one.
 */
class Scene : public sf::Drawable
{
    public:
        /**
         * @brief For the handling event loop.
         * 
         * @param event The event to handle.
         * @param mousePosition The mouse position to handle.
         */
        virtual void handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition) = 0;

        /**
         * @brief For the update time, after the event loop.
         * 
         * @param frameTime The time of the main loop.
         */
        virtual void update(const sf::Time& frameTime) = 0;

        /**
         * @brief Indicates if the scene is ended or not.
         * 
         * @return true If it's ended.
         * @return false If it's running.
         */
        bool inline isEnded()
        {
            return ended;
        }

    protected:
        bool ended;
};

#endif