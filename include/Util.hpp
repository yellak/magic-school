#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>

namespace Util
{
    namespace Transform
    {
        /**
         * @brief Centries the origin of a transformable entity.
         * The template class has to be or inherit from sf::Transformable.
         * 
         * @tparam Transformable Transformable class.
         * @param entity The entity that is going to have the center 
         */
        template <class Transformable>
        static inline void centreOrigin(Transformable& entity)
        {
            sf::FloatRect bounds = entity.getLocalBounds();
            float x = bounds.left + bounds.width/2.f;
            float y = bounds.top + bounds.height/2.f;
            entity.setOrigin(std::floor(x), std::floor(y));
        }
    }
}

#endif