#ifndef _PLAY_SCENE_HPP_
#define _PLAY_SCENE_HPP_

#include <Scene.hpp>

namespace scene
{
    class Play : public Scene
    {
        public:
            /**
             * @brief Construct a new Play object.
             */
            Play();

            /**
             * @see Scene::handleEvent
             */
            void handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition);

            /**
             * @see Scene::update
             */
            void update(const sf::Time& frameTime);
        
        protected:
            /**
             * @see sf::Translformable::draw
             */
            void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    };
}

#endif