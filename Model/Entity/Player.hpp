#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Input/PlayerInput.hpp"
#include "../Component/Script/PlayerMovement.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    using namespace components;

    class Player : public GameObject {
        public:
            Player(std::string strName);
            Player(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}
