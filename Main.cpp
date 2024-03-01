#include <iostream>
#include <unordered_map>
#include "SFML/Graphics.hpp"

#include "Controller/Game.cpp"
#include "Controller/SingletonTemplate.cpp"

#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/SceneManager.cpp"

#include "Model/GameObject.cpp"
#include "Model/AnimatedTexture.cpp"
#include "Model/Scene.cpp"

#include "Model/Entity/Player.cpp"
#include "Model/Entity/Background.cpp"

#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"

#include "Model/Component/Input/PlayerInput.cpp"
#include "Model/Component/Input/BackgroundInput.cpp"

#include "Model/Component/Script/PlayerMovement.cpp"
#include "Model/Component/Script/BackgroundAction.cpp"

#include "Model/Component/Renderer/Renderer.cpp"

#include "Model/Scene/MainMenuScene.cpp"
#include "Model/Scene/GameScene.cpp"

using namespace controllers;

int main() {
   Game CGame;
   CGame.run();

   return 0;
}