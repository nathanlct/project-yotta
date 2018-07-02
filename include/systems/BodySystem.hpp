#pragma once

#include <entityx/entityx.h>

#include <components/Body.hpp>

namespace ex = entityx;

struct BodySystem : public ex::System<BodySystem> {
  void update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt) override {
    const float fdt = static_cast<float>(dt);
    es.each<Body>([fdt](ex::Entity entity, Body &body) {
      body.position += body.direction * fdt;
    });
  };
};
