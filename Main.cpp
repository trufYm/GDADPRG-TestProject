#include "SFML/Graphics.hpp"
#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"

#include "Controller/Game.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/SceneManager.cpp"
#include "Controller/Manager/ObjectPoolManager.cpp"
#include "Controller/Pooling/GameObjectPool.cpp"

#include "Model/AnimatedTexture.cpp"
#include "Model/EmptyGameObject.cpp"
#include "Model/GameObject.cpp"
#include "Model/Entity/Background.cpp"
#include "Model/Entity/Ship.cpp"
#include "Model/Pooling/PoolableObject.cpp"
#include "Model/Pooling/Entity/PlayerBullet.cpp"
#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"
#include "Model/Component/Input/BackgroundInput.cpp"
#include "Model/Component/Script/BackgroundAction.cpp"
#include "Model/Component/Renderer/Renderer.cpp"

#include "Model/Scene.cpp"
#include "Model/Scene/MainMenuScene.cpp"
#include "Model/Scene/GameScene.cpp"

#include "Model/Component/Input/ShipInput.cpp"
#include "Model/Component/Script/BulletMovement.cpp"
#include "Model/Component/Script/ShipControls.cpp"

#include "Model/Component/Physics/Collider.cpp"
#include "Model/Entity/Border.cpp"
#include "Controller/Manager/PhysicsManager.cpp"

int main() {
    Game CGame;
    CGame.run();
    
    return 0;
}
