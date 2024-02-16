#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName){
    this->bMovingLeft = false;
    this->bMovingRight = false;
}

void PlayerInput::perform(){
    switch(this->CEvent.type){
        case sf::Event::KeyPressed:
            processKeyboardInput(CEvent.key.code, true);
            break;
        case sf::Event::KeyReleased:
            processKeyboardInput(CEvent.key.code, false);
            break;
        default:
            break;
    }
}

void PlayerInput::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed){
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
        
bool PlayerInput::getMovingLeft(){
    return this->bMovingLeft;
}

bool PlayerInput::getMovingRight(){
    return this->bMovingRight;
}

