#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, float fSpeed) {
    this->bEnabled = true;
    this->strName = strName;
    this->fSpeed = fSpeed;
    this->pSprite = new sf::Sprite();
}

bool GameObject::getEnabled() {
    return this->bEnabled;
}

std::string GameObject::getName() {
    return this->strName;
}

sf::Sprite* GameObject::getSprite() {
    return this->pSprite;
}

void GameObject::setTexture(sf::Texture* pTexture) {
    this->pTexture = pTexture;
    this->pSprite->setTexture(*this->pTexture);
}

float GameObject::getSpeed(){
    return this->fSpeed;
}
