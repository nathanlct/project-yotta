#pragma once

#include <entityx/entityx.h>

#include <components/Position.hpp>
#include <components/Direction.hpp>

namespace ex = entityx;

class MovementSystem : public ex::System<MovementSystem> {
public:
  void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override;
};
