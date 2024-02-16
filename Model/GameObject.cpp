#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, float fSpeed) {
    this->bEnabled = true;
    this->strName = strName;
    this->fSpeed = fSpeed;
    this->pSprite = new sf::Sprite();
}

GameObject::GameObject(std::string strName, float fSpeed, AnimatedTexture* pAnimatedTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->fSpeed = fSpeed;
    this->pSprite = new sf::Sprite();
    this->pAnimatedTexture = pAnimatedTexture;
    this->setFrame(0);
}


/* [TODO][2] :
   Update this class' content based on the lecture
   slides. */
void GameObject::processEvents(sf::Event CEvent){
    /*switch(CEvent.type){
        case sf::Event::KeyPressed:
            processKeyboardInput(CEvent.key.code, true);
            break;
        case sf::Event::KeyReleased:
            processKeyboardInput(CEvent.key.code, false);
            break;
        default:
            break;
    }*/
}
void GameObject::draw(sf::RenderWindow* pWindow){
    pWindow->draw(*this->pSprite);
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

void GameObject::setFrame(int nFrame){
    if(pAnimatedTexture != NULL){
        this->pAnimatedTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pAnimatedTexture->getFrame());
    }
}

float GameObject::getSpeed() {
    return this->fSpeed;
}

void GameObject::attachComponent(Component* pComponent){
    this->vecComponents.push_back(pComponent);
    pComponent->attachOwner(this);
}

void GameObject::detachComponent(Component* pComponent){
    int nIndex = -1;
    for(int i = 0; i < this->vecComponents.size(); i++){
        if(vecComponents[i] == pComponent)
            nIndex = i;
    }

    if(nIndex != -1){
        this->vecComponents[nIndex]->detachOwner();
        this->vecComponents.erase(this->vecComponents.begin() + nIndex);
    }
}

Component* GameObject::findComponentByName(std::string strName){
    for (Component* pComponent : this->vecComponents){
        if(pComponent->getName() == strName){
            return pComponent;
            break;
        }
    }

    return NULL;
}

std::vector<Component*> GameObject::getComponents(ComponentType EType){
    std::vector<Component*> vecTemp;

    for (Component* pComponent : this->vecComponents){
        if(pComponent->getType() == EType)
            vecTemp.push_back(pComponent);
    }

    return vecTemp;
}
