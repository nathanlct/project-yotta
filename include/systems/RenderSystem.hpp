#pragma once

#include <entityx/entityx.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <components/Position.hpp>
#include <components/Renderable.hpp>

namespace ex = entityx;

class RenderSystem : public ex::System<RenderSystem> {
public:
  explicit RenderSystem(sf::RenderTarget &target, unsigned short max_z);
	void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override;

private:
  sf::RenderTarget &target;
  int frame_count = 0;
  double last_update = 0.0;
  unsigned short max_z;
};
