#include "Application.hpp"

// maybe remove this class, since Game handles drawing

Application::Application()
{

}

void Application::run() {
  sf::RenderWindow window(sf::VideoMode(1024, 768), "Yotta");

  Game game(window);
  game.start();

  constexpr float MAX_FPS = 60;
  const float time_between_frames = 1.0 / MAX_FPS;

  sf::Clock clock;
  while (window.isOpen()) {
    if (clock.getElapsedTime().asSeconds() >= time_between_frames) {
      window.clear();

      sf::Time elapsed = clock.restart();
      game.update(elapsed.asSeconds());
      window.display();
    }
  }
}
