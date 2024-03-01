#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bMovingLeft;
            bool bMovingRight;
            bool bMovingUp;
            bool bMovingDown;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);
        
        public:
            bool getMovingLeft();
            bool getMovingRight();
            bool getMovingUp();
            bool getMovingDown();
    };
}
