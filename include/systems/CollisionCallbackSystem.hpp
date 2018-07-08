#pragma once

#include <entityx/entityx.h>

#include <components/Position.hpp>
#include <components/Direction.hpp>
#include <components/Collideable.hpp>

namespace ex = entityx;

class CollisionCallbackSystem : public ex::System<CollisionCallbackSystem> {
public:
  void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override;
};
