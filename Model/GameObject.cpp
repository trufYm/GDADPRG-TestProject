#include "GameObject.hpp"

using namespace models;

GameObject::GameObject() {
    this->fSpeed = 300.0f;
    this->isMovingLeft = false;
    this->isMovingRight = false;
}

//Methods
void GameObject::renderTo(sf::RenderWindow* CWindow){
    this->imgSprite.setPosition(0, 0);
    CWindow->draw(this->imgSprite);
}

//Getters & Setters
void GameObject::setTexture(sf::Texture CTexture) {
    this->CTexture = CTexture;
    this->imgSprite.setTexture(this->CTexture);
}

sf::Sprite* GameObject::getSprite() {
    return &this->imgSprite;
}

float GameObject::getSpeed() {
    return this->fSpeed;
}

bool GameObject::getMovingLeft(){
    return this->isMovingLeft;
}

void GameObject::setMovingLeft(bool isMovingLeft){
    this->isMovingLeft = isMovingLeft;
}

bool GameObject::getMovingRight(){
    return this->isMovingRight;
}

void GameObject::setMovingRight(bool isMovingRight){
    this->isMovingRight = isMovingRight;
}