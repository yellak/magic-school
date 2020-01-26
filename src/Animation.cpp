#include "Animation.hpp"

Animation::Animation(sf::Time totalTime, sf::Time switchTime) :
totalTime(totalTime),
switchTime(switchTime)
{
    current = sf::microseconds(0.f);
    ended = true;
}

void Animation::update(sf::Time frameTime)
{
    if (!ended)
    {
        current += frameTime;
        if (current >= totalTime)
        {
            current = sf::microseconds(0.f);
            ended = true;
            onTotalTime();
        }
        else if (current >= switchTime)
        {
            onSwitchTime();
        }
    }
}

void Animation::onTotalTime()
{
}

void Animation::onSwitchTime()
{
}

void Animation::start()
{
    this->ended = false;
}

void Animation::end()
{
    this->ended = true;
}

sf::Time Animation::getTotalTime()
{
    return totalTime;
}

void Animation::setTotalTime(sf::Time totalTime)
{
    this->totalTime = totalTime;
}

sf::Time Animation::getSwitchTime()
{
    return switchTime;
}

void Animation::setSwitchTime(sf::Time switchTime)
{
    this->switchTime = switchTime;
}

sf::Time Animation::getCurrent()
{
    return current;
}

void Animation::setCurrent(sf::Time current)
{
    this->current = current;
}

bool Animation::isEnded()
{
    return ended;
}
