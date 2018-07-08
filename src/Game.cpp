#include "Game.hpp"

Game::Game(sf::RenderWindow &window) :
  window(window),
  tm()
{
  systems.add<InputSystem>(window);
  systems.add<MovementSystem>();
  systems.add<CollisionCallbackSystem>();
  systems.add<CollisionSystem>();
  systems.add<RenderSystem>(window, 1);
  systems.configure();

  if (!tm.loadTileset("res/test_tileset.png", 32))
    fprintf(stderr, "ERROR: couldn't load tileset\n");
}


void Game::start() {
  /*

  EVERYTHING HERE IS TEMP

  rectangle movement not smooth, maybe draw with int instead of float

  try having shared_ptr of vectors2f for components (position, direction)

  */

  ex::Entity player = entities.create(); 

  player.assign<Position>(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
  player.assign<Direction>(sf::Vector2f(150, 80));

  sf::RectangleShape triangle(sf::Vector2f(60, 60));
  triangle.setFillColor(sf::Color(255, 100, 100));
  triangle.setOrigin(30, 30);
  player.assign<Renderable>(triangle, 1);

  player.assign<Collideable>();
  player.assign<Controllable>();

  if (!soundtrack.openFromFile("res/2.wav"))
    fprintf(stderr, "ERROR: couldn't load music\n");
  soundtrack.setLoop(true);
  soundtrack.setVolume(50);
  soundtrack.play();

  // 1024 x 768 = (32*32) x (24*32)
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 24; j++) {
      sf::Vector2u tile;
      bool solid = (i == 0 || i == 31 || j == 0 || j == 23);
      if (i == 0 || i == 31 || j == 0 || j == 23) tile = sf::Vector2u(0, 0);
      else if (i >= 2 && i <= 29 && j >= 2 && j <= 21) tile = sf::Vector2u(11, 9);
      else if (i == 1 && j == 1) tile = sf::Vector2u(10, 8);
      else if (i == 1 && j == 22) tile = sf::Vector2u(10, 10);
      else if (i == 1) tile = sf::Vector2u(10, 9);
      else if (i == 30 && j == 1) tile = sf::Vector2u(12, 8);
      else if (i == 30 && j == 22) tile = sf::Vector2u(12, 10);
      else if (i == 30) tile = sf::Vector2u(12, 9);
      else if (j == 1) tile = sf::Vector2u(11, 8);
      else tile = sf::Vector2u(11, 10);

      // if (i >= 1 && i <= 30 && j >= 1 && j <= 22) continue;
      tm.createTile(entities, tile, sf::Vector2f(i * 32, j * 32), solid);
    }
  }
}

void Game::pause() {

}

void Game::stop() {

}

void Game::update(ex::TimeDelta dt) {
  systems.update<InputSystem>(dt);

  systems.update<CollisionCallbackSystem>(dt);
  systems.update<MovementSystem>(dt);
  systems.update<CollisionSystem>(dt);

  systems.update<RenderSystem>(dt);
}
