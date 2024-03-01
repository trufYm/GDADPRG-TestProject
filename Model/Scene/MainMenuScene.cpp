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

    this->createBackground();
}

void MainMenuScene::onUnloadResources(){
    /*TextureManager::getInstance()->clearAll()*/
}

void MainMenuScene::createBackground(){
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MAIN_MENU_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}