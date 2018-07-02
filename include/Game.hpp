#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <entityx/entityx.h>

#include <iostream>

#include "systems/InputSystem.hpp"
#include "systems/BodySystem.hpp"
#include "systems/RenderSystem.hpp"

#include "components/Body.hpp"
#include "components/Renderable.hpp"
#include "components/Controllable.hpp"

namespace ex = entityx;


class Game : public ex::EntityX {
public:
  explicit Game(sf::RenderWindow &window);
  void start();
  void pause();
  void stop();
  void update(ex::TimeDelta dt);

private:
  sf::RenderWindow &m_window;
};
