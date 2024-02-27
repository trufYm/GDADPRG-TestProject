#pragma once

#include "../Scene.hpp"
#include "../Enum/SceneTag.hpp"

namespace scenes {
    class MainMenuScene : public Scene {
        public:
            MainMenuScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
            void onUnloadObjects();
        
        private:
            void createBackground();
    };
}
