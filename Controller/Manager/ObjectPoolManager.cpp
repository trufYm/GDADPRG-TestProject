#include "ObjectPoolManager.hpp"

using namespace managers;









/* * * * * * * * * * * * * * * * * * * * *
 *       SINGLETON-RELATED CONTENT       *
 * * * * * * * * * * * * * * * * * * * * */
ObjectPoolManager* ObjectPoolManager::P_SHARED_INSTANCE = NULL;

ObjectPoolManager::ObjectPoolManager() {}
ObjectPoolManager::ObjectPoolManager(const ObjectPoolManager&) {}

ObjectPoolManager* ObjectPoolManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new ObjectPoolManager();
    }

    return P_SHARED_INSTANCE;
}