#include "Game.hpp"

Game::Game(sf::RenderWindow &window) :
  m_window(window)
{
  systems.add<InputSystem>(m_window);
  systems.add<RenderSystem>(m_window);
  systems.configure();
}

void Game::start() {
  ex::Entity player = entities.create();

  player.assign<Body>(
    sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 2),
    sf::Vector2f(0, 0)
  );

  Renderable triangle(new sf::CircleShape(30, 3));
  triangle->setFillColor(sf::Color(255, 100, 100));
  triangle->setOrigin(30, 30);
  player.assign<Renderable>(triangle);

  player.assign<Controllable>();
}

void Game::pause() {

}

void Game::stop() {

}

void Game::update(ex::TimeDelta dt) {
  systems.update<InputSystem>(dt);
  // other systems..
  systems.update<RenderSystem>(dt);
}
