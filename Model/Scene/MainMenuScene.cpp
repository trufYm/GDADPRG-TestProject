#include "MainMenuScene.hpp"

using namespace scenes;

MainMenuScene::MainMenuScene() : Scene(SceneTag::MAIN_MENU_SCENE){

}

void MainMenuScene::onLoadResources(){
    TextureManager::getInstance()->loadMainMenu();
}

void MainMenuScene::onLoadObjects(){
    //AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    //Player* pPlayer = new Player("Player", pTexture);
    //this->registerObject(pPlayer);
}

void MainMenuScene::onUnloadResources(){
    /*TextureManager::getInstance()->clearAll()*/
}

void MainMenuScene::onUnloadObjects(){
    Scene::onUnloadObjects();
}

void MainMenuScene::createBackground(){

}