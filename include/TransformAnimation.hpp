#ifndef _TRANSFORM_ANIMATION_HPP_
#define _TRANSFORM_ANIMATION_HPP_

#include "Animation.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

class TransformAnimation : public Animation
{
    public:
        /**
         * @brief Construct a new Transform Animation object.
         * 
         * @param totalTime The total duration of the animation.
         * @param switchTime The time between switch states of the animation.
         */
        TransformAnimation(sf::Time totalTime, sf::Time switchTime);

        /**
         * @brief Set the switch method.
         * This method will be called when the switch time is reached.
         */
        void setSwitchMethod(std::function<void(void)>);

        /**
         * @brief Set the end method.
         * This method will be called when the total duration of the
         * animation is reached.
         */
        void setEndMethod(std::function<void(void)>);

    private:
        std::function<void(void)> endMethod;
        std::function<void(void)> switchMethod;

    protected:
        /**
         * @brief Runs when the animation ends.
         * This method is called when the animation reaches
         * its total time.
         */
        virtual void onTotalTime();

        /**
         * @brief Runs when the animation has to change state.
         * This method is called when switch time is reached, e.g.
         * when the animation state has to be updated.
         */
        virtual void onSwitchTime();
};

#endif