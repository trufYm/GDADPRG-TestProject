#include "GameObjectManager.hpp"

using namespace managers;

void GameObjectManager::processEvents(sf::Event CEvent) {
    /* [TODO][3] :
       Iterate over the [this->vecGameObject] field. If
       the [GameObject] inside the vector is ENABLED,
       call the [GameObject]'s [processEvents()]
       function. */
    
    for (GameObject* pGameObject : this->vecGameObject){
        if(pGameObject->getEnabled())
            pGameObject->processEvents(CEvent);
    }

    /*Above is equivalent to:
    for (int i = 0; i < this->vecGameObject.size(); i++){
        if(this->vecGameObject[i]->getEnabled())
            vecGameObject[i]->processEvents(CEvent);
    }*/
}

void GameObjectManager::update(sf::Time tDeltaTime) {
    /* [TODO][4] :
       Iterate over the [this->vecGameObject] field. If
       the [GameObject] inside the vector is ENABLED,
       call the [GameObject]'s [update()] function. */
    
    for (GameObject* pGameObject : this->vecGameObject){
        if(pGameObject->getEnabled())
            pGameObject->update(tDeltaTime);
    }
}

void GameObjectManager::draw(sf::RenderWindow* pWindow) {
    /* [TODO][5] :
       Iterate over the [this->vecGameObject] field. If
       the [GameObject] inside the vector is ENABLED,
       call the [GameObject]'s [draw()] function. */
    
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

/* * * * * * * * * * * * * * * * * * * * *
 *       SINGLETON-RELATED CONTENT       *
 * * * * * * * * * * * * * * * * * * * * */

/* [TODO][2] :
   Please make this a Singleton class.
   Place the Singleton-related content
   underneath this comment. */
GameObjectManager* GameObjectManager::P_SHARED_INSTANCE = NULL;

GameObjectManager::GameObjectManager() {}
GameObjectManager::GameObjectManager(const GameObjectManager&) {}

GameObjectManager* GameObjectManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new GameObjectManager();
    }

    return P_SHARED_INSTANCE;
}