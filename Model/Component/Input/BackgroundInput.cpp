#include "BackgroundInput.hpp"

using namespace components;

BackgroundInput::BackgroundInput(std::string strName) : GeneralInput(strName){
    this->bInteracted = false;
    this->bQuit = false;
}

void BackgroundInput::perform(){
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

void BackgroundInput::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed){
    switch (CKey) {
        case sf::Keyboard::Space:
            this->bInteracted = isPressed;
            break;
        case sf::Keyboard::Q:
            this->bQuit = isPressed;
        default:
            break;
    }
}
        
bool BackgroundInput::getInteract(){
    return this->bInteracted;
}

bool BackgroundInput::getQuit(){
    return this->bQuit;
}