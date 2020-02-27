#include <TransformAnimation.hpp>

TransformAnimation::TransformAnimation(sf::Time totalTime, sf::Time switchTime):
Animation(totalTime, switchTime)
{
}

void TransformAnimation::setSwitchMethod(std::function<void(void)> switchMethod)
{
    this->switchMethod = switchMethod;
}

void TransformAnimation::setEndMethod(std::function<void(void)> endMethod)
{
    this->endMethod = endMethod;
}

void TransformAnimation::onTotalTime()
{
    endMethod();
}

void TransformAnimation::onSwitchTime()
{
    switchMethod();
}