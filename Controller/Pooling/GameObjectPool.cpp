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
        vecAvailableObject.push_back(this->pPoolableReference->clone());
    }
}

PoolableObject* GameObjectPool::requestPoolable(){

}

void GameObjectPool::releasePoolable(PoolableObject* pPoolableObject){

}

void GameObjectPool::hasAvailable(int nRequestSize){

}

void GameObjectPool::setEnabled(PoolableObject* pPoolableObject, bool bEnabled){

}

PoolTag GameObjectPool::getTag(){
    return this->ETag;
}
