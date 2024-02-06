#pragma once

#include "../GameObject.hpp"

namespace entities{
    using namespace models;
    class Player : public GameObject{
        //Fields
        private:
            bool bMovingLeft;
            bool bMovingRight;

        //Constructors
        public:
            Player(std::string strName);

        //Methods
        public:
            void setMovingLeft(bool bMovingLeft);
            bool getMovingLeft();
            void setMovingRight(bool bMovingRight);
            bool getMovingRight();
    };
}