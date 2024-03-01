#include "GameScene.hpp"

using namespace scenes;

GameScene::GameScene() : Scene(SceneTag::GAME_SCENE){

}

void GameScene::onLoadResources(){
    TextureManager::getInstance()->loadGame();
}

void GameScene::onLoadObjects(){
    this->createBackground();

    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pPlayer = new Player("Player", pTexture);
    this->registerObject(pPlayer);
}

void GameScene::onUnloadResources(){
    /*TextureManager::getInstance()->clearAll()*/
}

void GameScene::createBackground(){
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::GAME_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}