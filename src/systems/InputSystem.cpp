#include "systems/InputSystem.hpp"


InputSystem::InputSystem(sf::RenderWindow &window)
  : window(window) {}

void InputSystem::update(ex::EntityManager &es, ex::EventManager &events, ex::TimeDelta dt)
{
  sf::Event event;
  while (window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyPressed:

        // TODO

      default:
        break;
    }
  }
}
