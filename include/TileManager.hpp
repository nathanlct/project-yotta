#pragma once

#include <SFML/Graphics.hpp>

#include <entityx/entityx.h>

#include "components/Position.hpp"
#include "components/Renderable.hpp"
#include "components/Solid.hpp"

namespace ex = entityx;

class TileManager {
public:
  explicit TileManager();
  bool loadTileset(const std::string& path, unsigned short tileSize);
  void createTile(ex::EntityManager &es, sf::Vector2u tile, sf::Vector2f pos, bool solid=false);

private:
  sf::Texture tileset;
  unsigned short tileSize;
};
