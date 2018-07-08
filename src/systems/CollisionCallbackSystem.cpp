#include "systems/CollisionCallbackSystem.hpp"

void CollisionCallbackSystem::update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) {

  es.each<Position, Direction, Collideable>([](ex::Entity entity, Position &pos, Direction &dir, Collideable &collideable) {
    collideable.positionCallback = pos.position;
  });
}
