#pragma once

#include <entityx/entityx.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace ex = entityx;

class InputSystem : public ex::System<InputSystem> {
public:
  explicit InputSystem(sf::RenderWindow &window);
	void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override;

private:
  sf::RenderWindow &window;
};
