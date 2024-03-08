#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Input/ShipInput.hpp"
//#include "../Component/Script/ShipControls.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    using namespace components;

    class Ship : public GameObject {
        public:
            Ship(std::string strName);
            Ship(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}
