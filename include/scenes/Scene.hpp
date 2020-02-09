#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

class Scene : public sf::Drawable
{
    public:
        virtual void handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition) = 0;

        virtual void update(const sf::Time& frameTime) = 0;

        bool inline isEnded()
        {
            return ended;
        }

    protected:
        bool ended;
};

#endif