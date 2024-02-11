#include <iostream>
#include <unordered_map>
#include "SFML/Graphics.hpp"

#include "Controller/Game.cpp"
#include "Model/GameObject.cpp"
#include "Controller/SingletonTemplate.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Model/Entity/Player.cpp"
#include "Controller/Manager/GameObjectManager.cpp"

using namespace controllers;

int main() {
   Game CGame;
   CGame.run();

   return 0;
}