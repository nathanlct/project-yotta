#pragma once

#include <entityx/entityx.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <components/Body.hpp>
#include <components/Renderable.hpp>

namespace ex = entityx;

class RenderSystem : public ex::System<RenderSystem> {
public:
  explicit RenderSystem(sf::RenderTarget &target);
	void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override;

private:
  sf::RenderTarget &m_target;
  int m_frame_count = 0;
  double m_last_update = 0.0;
};
