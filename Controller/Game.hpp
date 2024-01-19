#pragma once

#include "../Model/GameObject.hpp"

namespace controllers {
    class Game {
        //Fields
        private:
            sf::RenderWindow CWindow;
            models::GameObject CEntity;
            bool bCloseWindow = false;
        
        //Controllers
        public:
            Game();
        
        //Methods
        public:
            void run();
        
        private:
            void processEvents();
            void update();
            void render();
            void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);
    };
}