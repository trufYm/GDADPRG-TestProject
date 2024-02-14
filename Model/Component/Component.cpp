#include "Component.hpp"

using namespace components;

Component::Component(std::string strName, ComponentType EType){
    this->strName = strName;
    this->EType = EType;
    this->pOwner = NULL;
}

Component::~Component(){
    this->pOwner = NULL;
    //this->EType = ComponentType::NONE;
}
        
void Component::attachOwner(GameObject* pOwner){

}
void Component::detachOwner(){

}

void Component::perform(){

}
        
GameObject* Component::getOwner(){
    return this->pOwner;
}

ComponentType Component::getType(){
    return this->EType;
}

std::string Component::getName(){
    return this->strName;
}

sf::Time Component::getTime(){
    return this->tDeltaTime;
}