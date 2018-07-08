#pragma once

#include <SFML/Graphics.hpp>

#include <entityx/entityx.h>

#include <components/Position.hpp>
#include <components/Direction.hpp>
#include <components/Renderable.hpp>
#include <components/Solid.hpp>
#include <components/Collideable.hpp>

namespace ex = entityx;

class CollisionSystem : public ex::System<CollisionSystem> {
public:
  void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override;
};
