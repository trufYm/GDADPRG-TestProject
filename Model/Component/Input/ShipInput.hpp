#pragma once

#include "../GeneralInput.hpp"

namespace components {
    class ShipInput : public GeneralInput {
        private:
            bool bSpace;
            bool bUp;
            bool bDown;
            bool bLeft;
            bool bRight;
            
        public:
            ShipInput(std::string strName);

        public:
            void perform();
            void resetSpace();

        private:
            void processKeyInput(bool bPressed);

        public:
            bool getSpace();
            bool getUp();
            bool getDown();
            bool getLeft();
            bool getRight();
    };
}
