#pragma once

#include "../GeneralInput.hpp"

namespace components {
    /* [TODO] :
       Complete this class such that it listens to
       [SPACE] key inputs. */
    class BackgroundInput : public GeneralInput {
        private:
            bool bInteracted;

        public:
            BackgroundInput(std::string strName);
        
        public:
            void perform();

        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);
        
        public:
            bool getInteract();



    };
}
