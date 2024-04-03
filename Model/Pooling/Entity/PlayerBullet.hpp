#pragma once

#include "../PoolableObject.hpp"
#include "../../AnimatedTexture.hpp"
#include "../../Entity/Ship.hpp"
#include "../../Component/Script/BulletMovement.hpp"
#include "../../Component/Renderer/Renderer.hpp"
#include "../../Component/Physics/Collider.hpp"
#include "../../Interface/CollisionListener.hpp"
#include "../../../Controller/Manager/PhysicsManager.hpp"

namespace poolables {
    using namespace components;
    using namespace entities;
    using namespace models;
    
    class PlayerBullet : public PoolableObject, public CollisionListener {
        protected:
            Ship* pShip;

        private:
            bool bTopBounds;
            bool bLeftBounds;
            bool bBottomBounds;
            bool bRightBounds;

        public:
            PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip);

        public:
            void initialize();
            void onActivate();
            void onRelease();
            PoolableObject* clone();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);

        public:
            bool getTopBounds();
            bool getLeftBounds();
            bool getBottomBounds();
            bool getRightBounds();
    };
}