#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <entityx/entityx.h>

#include <iostream>

#include "TileManager.hpp"

#include "systems/InputSystem.hpp"
#include "systems/MovementSystem.hpp"
#include "systems/RenderSystem.hpp"
#include "systems/CollisionSystem.hpp"
#include "systems/CollisionCallbackSystem.hpp"

#include "components/Position.hpp"
#include "components/Direction.hpp"
#include "components/Renderable.hpp"
#include "components/Controllable.hpp"
#include "components/Collideable.hpp"

namespace ex = entityx;

class Game : public ex::EntityX {
public:
  explicit Game(sf::RenderWindow &window);
  void start();
  void pause();
  void stop();
  void update(ex::TimeDelta dt);

private:
  sf::RenderWindow &window;
  sf::Music soundtrack;
  TileManager tm;
};
