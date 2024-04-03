#include "ShipControls.hpp"

using namespace components;

ShipControls::ShipControls(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeed = 300.0f;
}

void ShipControls::perform() {
    Ship* pShipOwner = (Ship*)this->pOwner;
    ShipInput* pInput = (ShipInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");
    
    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();
        
        /** @note
          * If the user presses the [W] button and the [ShipOwner]
          * has NOT collided with the TOP BORDER, allow the [Ship]
          * to go UP. */
        if(pInput->getUp() && !pShipOwner->getTopBounds())
            this->getOwner()->getSprite()->move(0.0f, -fOffset);

        /** @note
          * If the user presses the [S] button and the [ShipOwner]
          * has NOT collided with the BOTTOM BORDER, allow the [Ship]
          * to go DOWN. */
        if(pInput->getDown() && !pShipOwner->getBottomBounds())
            this->getOwner()->getSprite()->move(0.0f, fOffset);

        /** @note
          * If the user presses the [A] button and the [ShipOwner]
          * has NOT collided with the LEFT BORDER, allow the [Ship]
          * to go LEFT. */
        if(pInput->getLeft() && !pShipOwner->getLeftBounds())
            this->getOwner()->getSprite()->move(-fOffset, 0.0f);

        /** @note
          * If the user presses the [D] button and the [ShipOwner]
          * has NOT collided with the RIGHT BORDER, allow the [Ship]
          * to go RIGHT. */
        if(pInput->getRight() && !pShipOwner->getRightBounds())
            this->getOwner()->getSprite()->move(fOffset, 0.0f);

        if(pInput->getSpace()) {
            pInput->resetSpace();
            ObjectPoolManager::getInstance()->getPool(PoolTag::PLAYER_BULLET)->requestPoolable();
        }
    }
}
