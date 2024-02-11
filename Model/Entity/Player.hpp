#pragma once

#include "../GameObject.hpp"

namespace entities {
    using namespace models;

    class Player : public GameObject {
        private:
            bool bMovingLeft;
            bool bMovingRight;

        public:
            Player(std::string strName);

        /* [TODO][1] :
           Update this class' content based on the lecture
           slides. */
        public:
            void initialize();
            void update(sf::Time tDeltaTime);
        
        protected:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed);

        public:
            bool getMovingLeft();
            void setMovingLeft(bool bMovingLeft);
            bool getMovingRight();
            void setMovingRight(bool bMovingRight);
    };
}
