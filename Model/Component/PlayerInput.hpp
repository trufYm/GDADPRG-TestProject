#pragma once

#include "GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        /* [TODO] :
           Create [PlayerInput] as a child of [GeneralInput]. This class
           will handle the Player's FLAG listening and will also contain
           [Player]'s [processKeyboardInput()] helper function. */
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
