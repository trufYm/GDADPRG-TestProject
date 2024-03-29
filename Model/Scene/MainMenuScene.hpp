#pragma once

#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Enum/AssetType.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Background.hpp"
#include "../Entity/Ship.hpp"
#include "../../Controller/Manager/TextureManager.hpp"

namespace scenes {
    using namespace models;
    using namespace entities;
    using namespace managers;
    class MainMenuScene : public Scene {
        public:
            MainMenuScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createBackground();
    };
}
