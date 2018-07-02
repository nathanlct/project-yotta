#include "systems/RenderSystem.hpp"


RenderSystem::RenderSystem(sf::RenderTarget &target)
  : m_target(target) {}

void RenderSystem::update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) {
  es.each<Body, Renderable>([this](ex::Entity entity, Body &body, Renderable &renderable) {
    renderable->setPosition(body.position);
    m_target.draw(*renderable.get());
  });

  m_last_update += dt;
  m_frame_count++;
  if (m_last_update >= 1.0) {
    const double fps = m_frame_count / m_last_update;
    printf("%zu entities (%d fps)\n", es.size(), static_cast<int>(fps));

    m_last_update = 0.0;
    m_frame_count = 0;
  }
}
