#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName) : GameObject(strName) {

}

Player::Player(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {

}

void Player::initialize(){
    this->pSprite->setPosition(100.0f, 100.0f);

    PlayerInput* pPlayerInput = new PlayerInput(this->strName + " Input");
    this->attachComponent(pPlayerInput);

    PlayerMovement* pPlayerMovement = new PlayerMovement(this->strName + " Movement");
    this->attachComponent(pPlayerMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}
