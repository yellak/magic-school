#ifndef _MAIN_MENU_SCENE_HPP_
#define _MAIN_MENU_SCENE_HPP_

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Button.hpp"

namespace scene
{
    class MainMenu : public Scene
    {
        public:
            MainMenu();

            void handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition);
            void update(sf::Time& frameTime);

        protected:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        private:
            Button playButton;
            sf::Texture playButtonTexture;
    };
}

#endif