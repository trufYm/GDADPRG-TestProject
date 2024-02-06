#pragma once

#include "../Model/Entity/Player.hpp"
#include "SingletonTemplate.hpp"
#include "Manager/TextureManager.hpp"
#include "../Model/Enum/AssetType.hpp"

namespace controllers {
    using namespace entities;
    using namespace managers;
    class Game {
        //Fields
        private:
            sf::RenderWindow CWindow;
            Player CEntity;
            bool bCloseWindow = false;
        
        //Controllers
        public:
            Game();
        
        //Methods
        public:
            void run();
        
        private:
            void processEvents();
            void update(sf::Time tTimePerFrame);
            void render();
            void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);
    };
}