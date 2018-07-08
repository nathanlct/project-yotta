#include "systems/RenderSystem.hpp"


RenderSystem::RenderSystem(sf::RenderTarget &target, unsigned short max_z)
  : target(target), max_z(max_z) {}

void RenderSystem::update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) {
  for (int z = 0; z <= max_z; z++) {
    es.each<Position, Renderable>([this,z](ex::Entity entity, Position &pos, Renderable &renderable) {
      if (renderable.z_axis == z) {
        renderable.shape.setPosition(pos.position);
        target.draw(renderable.shape);
      }
    });
  }

  last_update += dt;
  frame_count++;
  if (last_update >= 1.0) {
    const double fps = frame_count / last_update;
    printf("%zu entities (%d fps)\n", es.size(), static_cast<int>(fps));
    last_update = 0.0;
    frame_count = 0;
  }
}
