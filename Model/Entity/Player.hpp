#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"

namespace entities {
    using namespace models;

    class Player : public GameObject {
        public:
            Player(std::string strName);
            Player(std::string strName, AnimatedTexture* pTexture);

        /* [TODO][1] :
           Update this class' content based on the lecture
           slides. */
        public:
            void initialize();
            void update(sf::Time tDeltaTime);
        
        protected:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);
    };
}
