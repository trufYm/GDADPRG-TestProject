#include <iostream>
#include <unordered_map>
#include "SFML/Graphics.hpp"

#include "Controller/Game.cpp"
#include "Model/GameObject.cpp"
#include "Controller/SingletonTemplate.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Model/Entity/Player.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Model/AnimatedTexture.cpp"
#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"
#include "Model/Component/PlayerInput.cpp"

using namespace controllers;

int main() {
   Game CGame;
   CGame.run();

   return 0;
}