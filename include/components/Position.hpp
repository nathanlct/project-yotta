#pragma once


#include <SFML/System.hpp>

struct Position {
  Position(const sf::Vector2f &position)
    : position(position) {}

  sf::Vector2f position;
};
