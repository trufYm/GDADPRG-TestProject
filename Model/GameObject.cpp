#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, AnimatedTexture* pTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->pSprite = new sf::Sprite();
    this->pTexture = pTexture;
    this->setFrame(0);
}

GameObject::~GameObject() {}

void GameObject::processEvents(sf::Event CEvent) {
    std::vector<Component*> vecInputComponent = this->getComponents(ComponentType::INPUT);
    GeneralInput* pGeneralInput;

    for(Component* pComponent : vecInputComponent) {
        pGeneralInput = (GeneralInput*)pComponent;
        pGeneralInput->assignEvent(CEvent);
        pGeneralInput->perform();
    }
}

void GameObject::update(sf::Time tDeltaTime) {
    std::vector<Component*> vecScriptComponents = this->getComponents(ComponentType::SCRIPT);
    
    for(Component* pComponent : vecScriptComponents) {
        pComponent->setDeltaTime(tDeltaTime);
        pComponent->perform();
    }
}

void GameObject::draw(sf::RenderWindow* pWindow) {
    std::vector<Component*> vecRendererComponents = this->getComponents(ComponentType::RENDERER);
    
    for(Component* pComponent : vecRendererComponents) {
        Renderer* pRenderer = (Renderer*)pComponent;
        pRenderer->assignTargetWindow(pWindow);
        pRenderer->perform();
    }
}

void GameObject::centerOrigin() {
    if(this->pTexture != NULL) {
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = this->pSprite->getTexture()->getSize().y;
        this->pSprite->setOrigin(nWidth / 2.0f, nHeight / 2.0f);
    }
}

void GameObject::attachComponent(Component* pComponent) {
    this->vecComponent.push_back(pComponent);
    pComponent->attachOwner(this);
}

void GameObject::detachComponent(Component* pComponent) {
    int nIndex = -1;
    for(int i = 0; i < this->vecComponent.size() && nIndex == -1; i++) {
        if(this->vecComponent[i] == pComponent) {
            nIndex = i;
        }
    }

    if(nIndex != -1) {
        this->vecComponent[nIndex]->detachOwner();
        this->vecComponent.erase(this->vecComponent.begin() + nIndex);
    }
}

Component* GameObject::findComponentByName(std::string strName) {
    for(Component* pComponent : this->vecComponent) {
        if(pComponent->getName() == strName)
        return pComponent;
    }
    
    std::cout << "[ERROR] : Component [" << strName << "] NOT found." << std::endl;
    return NULL;
}

std::vector<Component*> GameObject::getComponents(ComponentType EType) {
    std::vector<Component*> vecFound = {};

    for(Component* pComponent : this->vecComponent) {
        if(pComponent->getType() == EType)
            vecFound.push_back(pComponent);
    }

    return vecFound;
}

float GameObject::getHalfWidth() {
    if(this->pTexture != NULL)
        return this->pSprite->getTexture()->getSize().x / 2.0f;
    return 0.0f;
}

float GameObject::getHalfHeight() {
    if(this->pTexture != NULL)
        return this->pSprite->getTexture()->getSize().y / 2.0f;
    return 0.0f;
}

sf::FloatRect GameObject::getGlobalBounds() {
    if(this->pSprite != NULL)
        return this->pSprite->getGlobalBounds();
    return sf::FloatRect();
}

bool GameObject::getEnabled() {
    return this->bEnabled;
}

void GameObject::setEnabled(bool bEnabled) {
    this->bEnabled = bEnabled;
}

std::string GameObject::getName() {
    return this->strName;
}

sf::Sprite* GameObject::getSprite() {
    return this->pSprite;
}

void GameObject::setFrame(int nFrame) {
    if(this->pTexture != NULL) {
        this->pTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pTexture->getFrame());
    }
}
