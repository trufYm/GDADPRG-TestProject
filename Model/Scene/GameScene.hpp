#pragma once

#include "../Enum/SceneTag.hpp"
#include "../Enum/AssetType.hpp"
#include "../Enum/PoolTag.hpp"
#include "../AnimatedTexture.hpp"
#include "../Scene.hpp"
#include "../Entity/Ship.hpp"
#include "../Entity/Border.hpp"
#include "../EmptyGameObject.hpp"
#include "../Pooling/Entity/PlayerBullet.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/GameObjectManager.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"

namespace scenes {
    using namespace entities;
    using namespace managers;
    using namespace models;
    using namespace poolables;

    class GameScene : public Scene {
        public:
            GameScene();
        
        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createNullObjects();
            void createBackground();
            void createShip();
            void createObjectPools();
            void createBorders();
    };
}
