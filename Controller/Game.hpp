#pragma once

#include "../Model/GameObject.hpp"

namespace controllers {
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