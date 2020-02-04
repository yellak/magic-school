#include "MainMenu.hpp"

namespace scene
{
    MainMenu::MainMenu()
    {
        playButtonTexture.loadFromFile("assets/textures/defaultButton.png");
        playButton.setTexture(playButtonTexture);
        playButton.move(100.f, 100.f);
    }

    void MainMenu::handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition)
    {
        playButton.handleEvent(event, mousePosition);
    }

    void MainMenu::update(sf::Time& frameTime)
    {
        playButton.update(frameTime);
    }

    void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(playButton, states);
    }
}