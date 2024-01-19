#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(sf::Texture CTexture) {
    this->setTexture(CTexture);
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