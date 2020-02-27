#ifndef _MAIN_MENU_SCENE_HPP_
#define _MAIN_MENU_SCENE_HPP_

#include <SFML/Graphics.hpp>
#include <Scene.hpp>
#include <Button.hpp>
#include <PathLoader.hpp>

namespace scene
{
    class MainMenu : public Scene
    {
        public:
            /**
             * @brief Construct a new Main Menu object.
             */
            MainMenu(const sf::RenderWindow&);

            /**
             * @brief Handle event method.
             * Called inside the handel event loop.
             * 
             * @param event Event that have to be handled.
             * @param mousePosition Mouse position.
             */
            void handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition);

            /**
             * @brief Update the Scene.
             * Called in after the handle event loop.
             * 
             * @param frameTime 
             */
            void update(const sf::Time& frameTime);

        protected:
            /**
             * @see sf::Translformable::draw
             */
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        private:
            /**
             * @brief The play button.
             */
            Button playButton;

            /**
             * @brief The texture of the play button.
             */
            sf::Texture playButtonTexture;

            /**
             * @brief The background of the main menu.
             */
            sf::Sprite background;

            sf::Texture backgroundTexture;

            /**
             * @brief Load the background of the menu.
             * 
             * @param size The size of the background.
             */
            void loadBackgroung(const sf::Vector2u& size);

            /**
             * @brief Load the button properties.
             * Charges the button with the texture, the text. Loads
             * its position and other things if necessary.
             * 
             * @param backgroundSize 
             */
            void loadButton(const sf::Vector2u& backgroundSize);
    };
}

#endif