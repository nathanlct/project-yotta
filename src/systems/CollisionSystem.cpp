#include "systems/CollisionSystem.hpp"

void CollisionSystem::update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) {
  ex::ComponentHandle<Position> pos1, pos2;
  ex::ComponentHandle<Solid> solid2;
  ex::ComponentHandle<Collideable> collideable1;
  ex::ComponentHandle<Renderable> renderable1, renderable2;
  ex::ComponentHandle<Direction> dir1;

  for (ex::Entity e1 : es.entities_with_components(pos1, dir1, collideable1, renderable1)) {
    for (ex::Entity e2 : es.entities_with_components(pos2, solid2, renderable2)) {
      if (e1 != e2) {
        sf::FloatRect e1_hitbox(pos1->position - renderable1->shape.getOrigin(), renderable1->shape.getSize());
        sf::FloatRect e2_hitbox(pos2->position - renderable2->shape.getOrigin(), renderable2->shape.getSize());
        if (e1_hitbox.intersects(e2_hitbox)) {
          /*
          TODO
            - emit an event when collision?
            - let the entity slide along the wall if she is going diagonally?
            - fix: if the entity is fast enough, there will be a gap between it and the wall
          */
          pos1->position = collideable1->positionCallback;
        }
      }
    }
  }




}
