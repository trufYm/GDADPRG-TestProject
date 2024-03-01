#pragma once

#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"
#include "../AnimatedTexture.hpp"
#include "../Entity/Background.hpp"
#include "../Entity/Player.hpp"

namespace scenes {
    using namespace models;
    using namespace entities;
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
