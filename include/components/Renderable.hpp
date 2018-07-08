#pragma once

#include <SFML/Graphics.hpp>


struct Renderable {
  Renderable(const sf::RectangleShape &shape, unsigned short z_axis) : shape(shape), z_axis(z_axis)
  {}

  sf::RectangleShape shape;
  unsigned short z_axis;
};
