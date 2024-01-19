#pragma once

#include <iostream>
#include "../Model/GameObject.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

namespace controllers {
    class Game {
        //Fields
        private:
            sf::RenderWindow CWindow;
            models::GameObject* CEntity;
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
    };
}