#include "GameObjectPool.hpp"

using namespace poolables;

GameObjectPool::GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference){
    this->ETag = ETag;
    this->nPoolSize = nPoolSize;
    this->pPoolableReference = pPoolableReference;
    this->vecAvailableObject = {};
    this->vecUsedObject = {};
}

void GameObjectPool::initialize(){
    for(int i = 0; i < nPoolSize; i++){
        PoolableObject* pClone = this->pPoolableReference->clone();

        GameObjectManager::getInstance()->addObject(pClone);
        pClone->setEnabled(false);
        vecAvailableObject.push_back(pClone);
    }
}

PoolableObject* GameObjectPool::requestPoolable(){
    if(this->hasAvailable(1)){
        this->vecUsedObject.push_back(this->vecAvailableObject[0]);
        this->vecAvailableObject.erase(this->vecAvailableObject.begin());

        this->setEnabled(this->vecUsedObject[0], true);
        return this->vecUsedObject[0];
    }

    return NULL;
}

void GameObjectPool::releasePoolable(PoolableObject* pPoolableObject){

}

bool GameObjectPool::hasAvailable(int nRequestSize){
    //if(this->vecAvailableObject.size() >= nRequestSize)
        //return true;
    //return false;

    return this->vecAvailableObject.size() >= nRequestSize;
}

std::vector<PoolableObject*> GameObjectPool::requestPoolableBatch(int nRequestSize){
    
}

void GameObjectPool::setEnabled(PoolableObject* pPoolableObject, bool bEnabled){
    pPoolableObject->setEnabled(bEnabled);
    if(bEnabled)
        pPoolableObject->onActivate();
    else
        pPoolableObject->onRelease();
}

PoolTag GameObjectPool::getTag(){
    return this->ETag;
}
