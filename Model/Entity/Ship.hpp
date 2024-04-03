#pragma once

#include "../../Config/Settings.hpp"
#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Input/ShipInput.hpp"
#include "../Component/Script/ShipControls.hpp"
#include "../Component/Physics/Collider.hpp"
#include "../Interface/CollisionListener.hpp"
#include "../../Controller/Manager/PhysicsManager.hpp"

namespace entities {
    using namespace managers;
    using namespace models;
    using namespace components;
    using namespace interfaces;

    class Ship : public GameObject, public CollisionListener {
        private:
            sf::Color CNormalColour;
            bool bTopBounds;
            bool bLeftBounds;
            bool bBottomBounds;
            bool bRightBounds;
            
        public:
            Ship(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
            void onCollisionEnter(GameObject* pGameObject);
            void onCollisionExit(GameObject* pGameObject);
        
        public:
            bool getTopBounds();
            bool getLeftBounds();
            bool getBottomBounds();
            bool getRightBounds();
    };
}