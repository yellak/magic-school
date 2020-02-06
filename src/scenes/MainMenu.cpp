#include "MainMenu.hpp"

namespace scene
{
    MainMenu::MainMenu(const sf::RenderWindow& window)
    {
        loadButton(window.getSize());
        loadBackgroung(window.getSize());
    }

    void MainMenu::loadBackgroung(const sf::Vector2u& size)
    {
        backgroundTexture.loadFromFile("assets/textures/mainMenuBackground.png");
        background.setTexture(backgroundTexture);

        float x = size.x/background.getLocalBounds().width;
        float y = size.y/background.getLocalBounds().height;
        background.setScale(x, y);
        Util::Transform::centreOrigin(background);
        background.setPosition(std::floor(size.x/2.f), std::floor(size.y/2.f));
    }

    void MainMenu::loadButton(const sf::Vector2u& backgroundSize)
    {
        playButtonTexture.loadFromFile("assets/textures/defaultButton.png");
        playButton.setTexture(playButtonTexture);

        float x = backgroundSize.x/2.f;
        float y = backgroundSize.y/2.f;
        playButton.move(x, y);
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
        target.draw(background, states);
        target.draw(playButton, states);
    }
}