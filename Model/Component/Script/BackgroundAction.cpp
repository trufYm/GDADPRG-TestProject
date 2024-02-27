#include "BackgroundAction.hpp"

using namespace components;

BackgroundAction::BackgroundAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {}

void BackgroundAction::perform() {
    BackgroundInput* pInput = /* [TODO] : Search for [BackgroundInput]. */

    if(pInput == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        if(pInput->getInteract()) {
            /* [TODO] :
               Use [SceneManager] to switch to the [GameScene]. */
        }
    }   
}
