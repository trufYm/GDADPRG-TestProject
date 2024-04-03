#pragma once

#include "../Enum/SceneTag.hpp"
#include "../Enum/AssetType.hpp"
#include "../AnimatedTexture.hpp"
#include "../Scene.hpp"
#include "../Entity/Background.hpp"
#include "../../Controller/Manager/TextureManager.hpp"

namespace scenes {
    using namespace entities;
    using namespace managers;
    using namespace models;

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
