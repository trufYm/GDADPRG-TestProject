#include "GameObjectPool.hpp"

using namespace poolables;

GameObjectPool::GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference) {
    this->ETag = ETag;
    this->nPoolSize = nPoolSize;
    this->pPoolableReference = pPoolableReference;

    this->vecAvailableObject = {};
    this->vecUsedObject = {};
}

void GameObjectPool::initialize() {
    for(int i = 0; i < this->nPoolSize; i++) {
        PoolableObject* pPoolableObject = this->pPoolableReference->clone();
        GameObjectManager::getInstance()->addObject(pPoolableObject);
        pPoolableObject->setEnabled(false);

        this->vecAvailableObject.push_back(pPoolableObject);
    }
}

PoolableObject* GameObjectPool::requestPoolable() {
    if(this->hasAvailable(1)) {
        PoolableObject* pPoolableObject = this->vecAvailableObject[0];
        this->vecUsedObject.push_back(pPoolableObject);
        this->vecAvailableObject.erase(this->vecAvailableObject.begin());
        this->setEnabled(pPoolableObject, true);
        return pPoolableObject;
    }
    return NULL;
}

void GameObjectPool::releasePoolable(PoolableObject* pPoolableObject) {
    int nIndex = -1;
    for(int i = 0; i < this->vecUsedObject.size() && nIndex == -1; i++) {
        if(this->vecUsedObject[i] == pPoolableObject)
            nIndex = i;
    }

    if(nIndex != -1) {
        this->vecAvailableObject.push_back(pPoolableObject);
        this->vecUsedObject.erase(this->vecUsedObject.begin() + nIndex);
        this->setEnabled(pPoolableObject, false);
    }
}

bool GameObjectPool::hasAvailable(int nRequestSize) {
    if(this->vecAvailableObject.size() >= nRequestSize)
        return true;
    return false;
}

void GameObjectPool::setEnabled(PoolableObject* pPoolableObject, bool bEnabled) {
    pPoolableObject->setEnabled(bEnabled);
    if(bEnabled)
        pPoolableObject->onActivate();
    else
        pPoolableObject->onRelease();
}

PoolTag GameObjectPool::getTag() {
    return this->ETag;
}
