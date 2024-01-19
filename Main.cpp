#include <iostream>
#include "SFML/Graphics.hpp"

#include "Controller/Game.cpp"
#include "Model/GameObject.cpp"

using namespace controllers;

int main() {
   Game CGame;
   CGame.run();

   return 0;
}