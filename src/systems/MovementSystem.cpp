#include "systems/MovementSystem.hpp"

void MovementSystem::update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) {
  const float fdt = static_cast<float>(dt);
  es.each<Position, Direction>([fdt](ex::Entity entity, Position &pos, Direction &dir) {
    pos.position += dir.direction * fdt;
  });
}
