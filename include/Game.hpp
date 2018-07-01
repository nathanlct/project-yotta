#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <entityx/entityx.h>

#include <iostream>

namespace ex = entityx;


class Game : public ex::EntityX {
public:
  Game(sf::RenderTarget &target);
  void start();
  void pause();
  void stop();
  void update(ex::TimeDelta dt);

private:
  sf::RenderTarget &m_target;
};
