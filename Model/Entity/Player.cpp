#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName) : GameObject(strName, 300.0f) {

}

Player::Player(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {

}

void Player::initialize(){
    this->pSprite->setPosition(100.0f, 100.0f);

    PlayerInput* pPlayerInput = new PlayerInput(this->strName + " Input");
    this->attachComponent(pPlayerInput);

    PlayerMovement* pPlayerMovement = new PlayerMovement(this->strName + " Movement");
    this->attachComponent(pPlayerMovement);

    /*Renderer* pRenderer = new Renderer();
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);*/
}

//void Player::update(sf::Time tDeltaTime){
    /*if(this->bMovingLeft){
        this->pSprite->move(-1.0f * this->fSpeed * tDeltaTime.asSeconds(), 0.0f);
        this->setFrame(1);
    }

    if(this->bMovingRight){
        this->pSprite->move(1.0f * this->fSpeed * tDeltaTime.asSeconds(), 0.0f);
        this->setFrame(0);
    }*/

    //Broken
    //this->pAnimatedTexture->incrementFrame();
    //this->setTexture(this->pAnimatedTexture->getFrame());
//}

/*void Player::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed){
    switch (CKey) {
        case sf::Keyboard::A:
            this->bMovingLeft = isPressed;
            break;
        case sf::Keyboard::D:
            this->bMovingRight = isPressed;
            break;
        default:
            break;
    }
}*/

