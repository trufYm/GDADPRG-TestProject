#pragma once

#include "../Model/GameObject.hpp"
#include "SingletonTemplate.hpp"
#include "Manager/TextureManager.hpp"

namespace controllers {
    using namespace models;
    using namespace managers;
    class Game {
        //Fields
        private:
            sf::RenderWindow CWindow;
            models::GameObject CEntity;
            models::GameObject CDonPer;
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