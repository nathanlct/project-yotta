#pragma once


#include <SFML/System.hpp>

struct Body {
  Body(const sf::Vector2f &position, const sf::Vector2f &direction)
    : position(position), direction(direction) {}

  sf::Vector2f position;
  sf::Vector2f direction;
};
