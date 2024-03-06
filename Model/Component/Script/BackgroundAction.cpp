#include "BackgroundAction.hpp"

using namespace components;

BackgroundAction::BackgroundAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void BackgroundAction::perform() {
    BackgroundInput* pInput = (BackgroundInput*)this->pOwner->getComponents(ComponentType::INPUT)[0];
    //BackgroundInput* pInput = (BackgroundInput*)this->getOwner()->findComponentByName(this->pOwner->getName() + " Input");/* [TODO] : Search for [BackgroundInput]. */

    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->getInteract()) {
            /* [TODO] :
               Use [SceneManager] to switch to the [GameScene]. */
            SceneManager::getInstance()->loadScene(SceneTag::GAME_SCENE);
        }
        else if(pInput->getQuit()){
            SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU_SCENE);
        }
    }   
}
