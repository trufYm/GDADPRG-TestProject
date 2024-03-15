#pragma once

#include "../Scene.hpp"
#include "../AnimatedTexture.hpp"

#include "../Enum/SceneTag.hpp"
#include "../Enum/AssetType.hpp"
#include "../Enum/PoolTag.hpp"

#include "../Entity/Background.hpp"
#include "../Entity/Ship.hpp"
#include "../Pooling/Entity/PlayerBullet.hpp"

#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/GameObjectManager.hpp"
#include "../../Controller/Pooling/GameObjectPool.hpp"

namespace scenes {
    using namespace models;
    using namespace entities;
    using namespace managers;
    using namespace poolables;
    class GameScene : public Scene {
        public:
            GameScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createBackground();
            void createShip();
            void createObjectPools();
    };
}
