#include "Application.hpp"

Application::Application()
{

}

void Application::run() {
  sf::RenderWindow window(sf::VideoMode(1024, 768), "Yotta");

  Game game(window);
  game.start();

  sf::Clock clock;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
        case sf::Event::KeyPressed:
          window.close();
          break;

        default:
          break;
      }
    }

    window.clear();
    sf::Time elapsed = clock.restart();
    game.update(elapsed.asSeconds());
    window.display();
  }
}
