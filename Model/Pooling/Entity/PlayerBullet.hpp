#pragma once

#include "../PoolableObject.hpp"
#include "../../Entity/Ship.hpp"
#include "../../AnimatedTexture.hpp"
#include "../../Enum/PoolTag.hpp"

namespace poolables{
    using namespace entities;
    class PlayerBullet : public PoolableObject{
        private:
            Ship* pShip;

        public:
            PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip);

        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();
    };
}