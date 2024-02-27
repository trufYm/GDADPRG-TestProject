#pragma once

#include "../Input/PlayerInput.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"

namespace components {
    class PlayerMovement : public Component {
        private:
            float fSpeed;

        public:
            PlayerMovement(std::string strName);

        public:
            void perform();
    };
}
