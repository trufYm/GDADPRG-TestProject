#pragma once

#include "../../Enum/ComponentType.hpp"
#include "../../Enum/PoolTag.hpp"
#include "../Component.hpp"
#include "../Input/ShipInput.hpp"
#include "../../../Controller/Manager/ObjectPoolManager.hpp"

namespace entities{
    class Ship;
}

namespace components {
    using namespace managers;
    using namespace entities;

    class ShipControls : public Component {
        private:
            float fSpeed;
            
        public:
            ShipControls(std::string strName);

        public:
            void perform();
    };
}
