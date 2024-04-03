#include "MainMenuScene.hpp"

using namespace scenes;

MainMenuScene::MainMenuScene() : Scene(SceneTag::MAIN_MENU_SCENE) {}

void MainMenuScene::onLoadResources() {
    TextureManager::getInstance()->loadMainMenu();
}

void MainMenuScene::onLoadObjects() {
    /* [TODO] :
       Make a [Background] [GameObject] instance then
       add it to the [Scene]. */
    this->createBackground();
}

void MainMenuScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void MainMenuScene::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MAIN_MENU_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}
