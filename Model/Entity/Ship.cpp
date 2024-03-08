#include "Ship.hpp"

using namespace entities;

Ship::Ship(std::string strName) : GameObject(strName) {

}

Ship::Ship(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {

}

void Ship::initialize(){
    this->pSprite->setPosition(100.0f, 100.0f);

    ShipInput* pShipInput = new ShipInput(this->strName + " Input");
    this->attachComponent(pShipInput);

    //ShipControls* pShipControls = new ShipControls(this->strName + " Movement");
    //this->attachComponent(pShipControls);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}
