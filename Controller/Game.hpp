#pragma once

#include "../Config/Settings.hpp"
#include "../Model/Enum/AssetType.hpp"
#include "../Model/Scene/MainMenuScene.hpp"
#include "../Model/Scene/GameScene.hpp"
#include "../Model/AnimatedTexture.hpp"
#include "Manager/TextureManager.hpp"
#include "Manager/GameObjectManager.hpp"
#include "Manager/SceneManager.hpp"

namespace controllers {
    using namespace managers;
    using namespace models;
    using namespace entities;
    using namespace scenes;

    class Game {
        private:
            sf::RenderWindow CWindow;

        public:
            Game();

        public:
            void run();

        private:
            void processEvents();
            void update(sf::Time tDeltaTime);
            void render();
    };
}