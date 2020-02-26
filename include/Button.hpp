#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include "Util.hpp"
#include "TransformAnimation.hpp"
#include "StateMachine.hpp"
#include "Listenable.hpp"


namespace states
{
    namespace button
    {
        class StandBy;
        class Clicking;
    }
}

/**
 * @brief Button class.
 * This class is used to create a new button to the game. The button
 * has a sprite with a texture that has to be provided outside, e.g. you
 * can create your own form button. The button does not have a flexible
 * bounding box, it means that the button will always have a squared bounding
 * box even if the texture isn't squared.
 * The button has to have a texture, if it does not, it won't work
 * properly.
 */
class Button : public sf::Drawable, public sf::Transformable, public Listenable
{
    friend class states::button::StandBy;
    friend class states::button::Clicking;

public:
    /**
     * @brief Construct a new Button object.
     * The Button made has position x = 0 and y = 0.
     */
    Button();

    /**
     * @brief Construct a new Button object.
     * 
     * @param totalAnimationTime The time that the click animation will take.
     * @param switchAnimantioTime The between switch states of the animation.
     */
    Button(sf::Time totalAnimationTime, sf::Time switchAnimantionTime);

    /**
     * @brief Destroy the Button object
     */
    ~Button();

    /**
     * @brief Return the bounds of the button.
     * 
     * @return sf::FloatRect The area that the button occupies.
     */
    sf::FloatRect getGlobalBounds();

    /**
     * @brief Return if the button has the position provided or not.
     * 
     * @param position The position that is going to be checked.
     * @return true If the position is inside the button.
     * @return false If it's not.
     */
    bool contains(const sf::Vector2f& position) const;

    /**
     * @brief Update the state of the button.
     * 
     * @param frameTime The time of a frame defined by the main loop.
     */
    void update(const sf::Time& frameTime);

    /**
     * @brief Handle an event coming from outside.
     * 
     * @param event The event initialized ouside of the Button.
     * @param mousePosition The mouse position relatively to the window where the Button is within.
     */
    void handleEvent(const sf::Event& event, const sf::Vector2f& mousePosition);

    /**
     * @brief Set the String of the text of the button.
     * 
     * @param string The new text String.
     */
    void setString(const sf::String& string);

    /**
     * @brief Set the Character Size of the text.
     * 
     * @param size The new size of the text.
     */
    void setCharacterSize(unsigned int size);

    void addClickListener(std::function<void(void)>);

    ////////////////////////////////////////////////////////////////
    // Public attributes
    ////////////////////////////////////////////////////////////////

    /**
     * @brief StandBy State of the Button.
     * In this state, the button is quiet, it's
     * doing nothing, neither clicking or jumping.
     */
    State* standBy;

    /**
     * @brief Clicking state of the Button.
     * In this state, the is running the click
     * animation. When the animation ends the button
     * stops clicking.
     */
    State* clicking;

    ////////////////////////////////////////////////////////////////
    // Getters and Setters
    ////////////////////////////////////////////////////////////////

    void setTexture(const sf::Texture&);

    sf::Text& getText();
    void setText(const sf::Text&);

    TransformAnimation& getClickAnimation();


private:
    /**
     * @brief Control the state handling of the Button.
     */
    StateMachine* state;

    /**
     * @brief The sprite of the button.
     * This is basically the shape of the button.
     */
    sf::Sprite sprite;

    /**
     * @brief The text of the button.
     */
    sf::Text text;

    /**
     * @brief The click animation of the button
     */
    TransformAnimation clickAnimation;
    /**
     * @brief Called when we want to draw the button.
     * 
     * @param target The window where the button is going to be drawn.
     * @param states The state object that specifies the next state of the button.
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * @brief Load the texture of the button.
     */
    void loadTexture();

    /**
     * @brief Set the sprite origin to the middle of the button.
     */
    void setSpriteOriginToMiddle();

    /**
     * @brief Set the Text Origin To Middle.
     */
    void setTextOriginToMiddle();
};

/**
 * @brief General States.
 * 
 */
namespace states
{
    /**
     * @brief States of the Button.
     */
    namespace button
    {
        /**
         * @brief StandBy state of the button.
         * At this state, the button has no action from any kind.
         */
        class StandBy : public State
        {
            public:
                inline StandBy(Button* button): button(button) {};

                virtual State* update(const sf::Time&);

                virtual State* handleEvent(const sf::Event&, const sf::Vector2f&);

            private:
                Button* button;
        };

        /**
         * @brief Clicking state of the button.
         * At this state, the button is making the click animation.
         */
        class Clicking : public State
        {
            public:
                inline Clicking(Button* button): button(button) {};

                virtual State* update(const sf::Time&);

                virtual State* handleEvent(const sf::Event&, const sf::Vector2f&);

            private:
                Button* button;
        };
    } // namespace button
} // namespace states

#endif