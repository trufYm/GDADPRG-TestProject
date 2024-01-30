#include <iostream>
#include <unordered_map>
#include "SFML/Graphics.hpp"

#include "Controller/Game.cpp"
#include "Model/GameObject.cpp"
#include "Controller/SingletonTemplate.cpp"
#include "Controller/Manager/TextureManager.cpp"

using namespace controllers;

int main() {
   Game CGame;
   CGame.run();

   return 0;
}