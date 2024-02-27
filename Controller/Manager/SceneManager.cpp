#include "SceneManager.hpp"

using namespace managers;

/* [TODO] :
   Fill this up based on the slides. */
void SceneManager::registerScene(Scene* pScene){
    this->mapScenes[pScene->getTag()] = pScene;
}

void SceneManager::loadScene(SceneTag ETag){
    this->bLoading = true;
    this->ESceneToLoad = ETag;
}
void SceneManager::unloadScene(){

}
void SceneManager::checkLoadScene(){

}
bool SceneManager::getLoaded(SceneTag ETag){

}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
SceneManager* SceneManager::P_SHARED_INSTANCE = NULL;
SceneManager::SceneManager() {
    this->pActiveScene = NULL;
}
SceneManager::SceneManager(const SceneManager&) {}

SceneManager* SceneManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new SceneManager();

    return P_SHARED_INSTANCE;
}
/* * * * * * * * * * * * * * * * * * * * */
