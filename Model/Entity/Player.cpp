#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName) : GameObject(strName, 300.0f){
    bMovingLeft = false;
    bMovingRight = false;
}

void Player::setMovingLeft(bool bMovingLeft){
    this->bMovingLeft = bMovingLeft;
}

bool Player::getMovingLeft(){
    return this->bMovingLeft;
}

void Player::setMovingRight(bool bMovingRight){
    this->bMovingRight = bMovingRight;
}

bool Player::getMovingRight(){
    return this->bMovingRight;
}