#ifndef _PLAY_SCENE_HPP_
#define _PLAY_SCENE_HPP_

#include "Scene.hpp"

namespace scene
{
    class Play : public Scene
    {
        public:
            Play();

            void handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition);

            void update(sf::Time& frameTime);
        
        protected:
            /**
             * @see sf::Translformable::draw
             */
            void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    };
}

#endif