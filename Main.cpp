#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "Controller/Game.hpp"

using namespace controllers;

int main() {
   Game CGame;
   CGame.run();

   return 0;
}

//Code for Square
/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Start-Up");
   sf::CircleShape shape(100.f);
   shape.setFillColor(sf::Color::Green);

   while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
         if (event.type == sf::Event::Closed)
            window.close();
      }

      window.clear();
      window.draw(shape);
      window.display();
   }*/
