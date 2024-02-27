#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bMovingLeft;
            bool bMovingRight;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);
        
        public:
            bool getMovingLeft();
            bool getMovingRight();
    };
}
