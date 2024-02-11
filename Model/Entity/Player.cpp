#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName) : GameObject(strName, 300.0f) {
    this->bMovingLeft = false;
    this->bMovingRight = false;
}

/* [TODO][2] :
   Update this class' content based on the lecture
   slides. */
void Player::initialize(){
    this->pSprite->setPosition(100.0f, 100.0f);
}

void Player::update(sf::Time tDeltaTime){
    if(this->bMovingLeft){
        this->pSprite->move(-1.0f * this->fSpeed * tDeltaTime.asSeconds(), 0.0f);
    }

    if(this->bMovingRight){
        this->pSprite->move(1.0f * this->fSpeed * tDeltaTime.asSeconds(), 0.0f);
    }
}

void Player::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed){
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
}

bool Player::getMovingLeft() {
    return this->bMovingLeft;
}

void Player::setMovingLeft(bool bMovingLeft) {
    this->bMovingLeft = bMovingLeft;
}

bool Player::getMovingRight() {
    return this->bMovingRight;
}

void Player::setMovingRight(bool bMovingRight) {
    this->bMovingRight = bMovingRight;
}
