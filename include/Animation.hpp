#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(sf::Time, sf::Time);

    void update(sf::Time);

    void start();
    void end();

    ///////////////////////////////////////////////////
    // Getter and setters
    ///////////////////////////////////////////////////
    
    sf::Time getTotalTime();
    void setTotalTime(sf::Time);

    sf::Time getSwitchTime();
    void setSwitchTime(sf::Time);

    sf::Time getCurrent();
    void setCurrent(sf::Time);

    bool isEnded();

private:
    /**
     * @brief The current time passed.
     */
    sf::Time current;

    /**
     * @brief The total time of the animation
     */
    sf::Time totalTime;

    /**
     * @brief The time between states of the animation.
     */
    sf::Time switchTime;

    /**
     * @brief Indicates if the animation is ended or not.
     */
    bool ended;

protected:
    virtual void onTotalTime();

    virtual void onSwitchTime();
};

#endif