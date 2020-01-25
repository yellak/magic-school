#ifndef _TRANSFORM_ANIMATION_HPP_
#define _TRANSFORM_ANIMATION_HPP_

#include "Animation.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

class TransformAnimation : public Animation
{
    public:
        TransformAnimation(sf::Time, sf::Time);

        void setSwitchMethod(std::function<void(void)>);
        void setEndMethod(std::function<void(void)>);

    private:
        std::function<void(void)> endMethod;
        std::function<void(void)> switchMethod;

    protected:
        virtual void onTotalTime();

        virtual void onSwitchTime();
};

#endif