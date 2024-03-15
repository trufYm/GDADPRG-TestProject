#include "Ship.hpp"

using namespace entities;

Ship::Ship(std::string strName) : GameObject(strName) {
    this->CNormalColor = sf::Color(0, 0, 0, 255);
}

Ship::Ship(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {

}

void Ship::initialize(){
    this->centerOrigin();
    this->pSprite->setColor(this->CNormalColor);
    this->pSprite->setPosition(90.f, 210.f);

    ShipInput* pShipInput = new ShipInput(this->strName + " Input");
    this->attachComponent(pShipInput);

    ShipControls* pShipControls = new ShipControls(this->strName + " Movement");
    this->attachComponent(pShipControls);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}
