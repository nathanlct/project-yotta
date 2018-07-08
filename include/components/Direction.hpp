#pragma once


#include <SFML/System.hpp>

struct Direction {
  Direction(const sf::Vector2f &direction)
    : direction(direction) {}

  sf::Vector2f direction;
};
