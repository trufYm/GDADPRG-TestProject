#include "GameObjectManager.hpp"

using namespace managers;

void GameObjectManager::processEvents(sf::Event CEvent) {
    for (GameObject* pGameObject : this->vecGameObject){
        if(pGameObject->getEnabled())
            pGameObject->processEvents(CEvent);
    }

    /*Range based for loop ^
    
    Above is equivalent to:
    for (int i = 0; i < this->vecGameObject.size(); i++){
        if(this->vecGameObject[i]->getEnabled())
            vecGameObject[i]->processEvents(CEvent);
    }*/
}

void GameObjectManager::update(sf::Time tDeltaTime) {
    for (GameObject* pGameObject : this->vecGameObject){
        if(pGameObject->getEnabled())
            pGameObject->update(tDeltaTime);
    }
}

void GameObjectManager::draw(sf::RenderWindow* pWindow) {
    for (GameObject* pGameObject : this->vecGameObject){
        if(pGameObject->getEnabled())
            pGameObject->draw(pWindow);
    }
}

void GameObjectManager::addObject(GameObject* pGameObject) {
    this->mapGameObject[pGameObject->getName()] = pGameObject;
    this->vecGameObject.push_back(pGameObject);
    pGameObject->initialize();
}

GameObject* GameObjectManager::findObjectByName(std::string strName) {
    if(this->mapGameObject[strName] != NULL)
        return this->mapGameObject[strName];

    else {
        std::cout << "[ERROR] : Object [" << strName << "] NOT found." << std::endl;
        return NULL;
    }
}

void GameObjectManager::deleteAllObjects(){
    std::vector<GameObject*> vecGameObject = this->vecGameObject;
    for(int i = 0; i < vecGameObject.size(); i++){
        delete this->vecGameObject[i];
    }

    this->vecGameObject.clear();
    this->mapGameObject.clear();
}

/* * * * * * * * * * * * * * * * * * * * *
 *       SINGLETON-RELATED CONTENT       *
 * * * * * * * * * * * * * * * * * * * * */
GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;

GameObjectManager::GameObjectManager() {}
GameObjectManager::GameObjectManager(const GameObjectManager&) {}

GameObjectManager* GameObjectManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new GameObjectManager();
    }

    return P_SHARED_INSTANCE;
}