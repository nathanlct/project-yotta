#include "TileManager.hpp"



TileManager::TileManager() :
  tileSize(0)
{}

bool TileManager::loadTileset(const std::string& path, unsigned short tileSize) {
  if (tileset.loadFromFile(path)) {
    this->tileSize = tileSize;
    return true;
  }
  else {
    return false;
  }
}

/*
TEMP
depends on how tileset will be handled
if it stays that way, give es to the ctor
*/
void TileManager::createTile(ex::EntityManager &es, sf::Vector2u tilesetPos, sf::Vector2f pos, bool solid) {
  ex::Entity tile = es.create();

  tile.assign<Position>(pos);

  sf::RectangleShape tileTexture(sf::Vector2f(tileSize, tileSize));
  tileTexture.setTexture(&tileset);
  tileTexture.setTextureRect(sf::IntRect(tilesetPos.x * tileSize, tilesetPos.y * tileSize, tileSize, tileSize));
  tile.assign<Renderable>(tileTexture, 0);

  if (solid)
    tile.assign<Solid>();
}
