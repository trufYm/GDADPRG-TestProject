#include "PlayerMovement.hpp"

using namespace components;

PlayerMovement::PlayerMovement(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fSpeed = 300.0f;
}

void PlayerMovement::perform() {
    /* [NOTE] : Load all dependencies. */
    PlayerInput* pPlayerInput = (PlayerInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");/* [TODO] : From the OWNER, look for the FIRST [INPUT]-type component. */;
    sf::Sprite* pSprite = this->pOwner->getSprite();/* [TODO] : Get the OWNER's SPRITE. */

    /* [NOTE] : ALWAYS perform NULL checking. */
    if(pPlayerInput == NULL || pSprite == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pPlayerInput->getMovingLeft()){
            pSprite->move(-1.0f * this->fSpeed * this->tDeltaTime.asSeconds(), 0.0f);
        }

        if(pPlayerInput->getMovingRight()){
            pSprite->move(1.0f * this->fSpeed * this->tDeltaTime.asSeconds(), 0.0f);
        }
    }   
}
