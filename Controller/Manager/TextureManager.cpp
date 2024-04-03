#include "TextureManager.hpp"

using namespace managers;

void TextureManager::loadMainMenu() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/main_menu_background.png");
    this->mapTexture[AssetType::MAIN_MENU_BACKGROUND].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::MAIN_MENU_BACKGROUND);
}

void TextureManager::loadGame() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/game_background.png");
    this->mapTexture[AssetType::GAME_BACKGROUND].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::GAME_BACKGROUND);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Player/this_ship_be_otp.png");
    this->mapTexture[AssetType::SHIP].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::SHIP);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Player/bullet.png");
    this->mapTexture[AssetType::BULLET].push_back(pTexture);
    this->vecAssetTypes.push_back(AssetType::BULLET);
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EType){
    return this->mapTexture[EType];
}

sf::Texture* TextureManager::getTextureAt(AssetType EType, int nFrame){
    return this->mapTexture[EType][nFrame];
}

void TextureManager::unloadAll() {
    for(AssetType EType : this->vecAssetTypes) {
        std::vector<sf::Texture*> vecTextures = this->mapTexture[EType];
        for(int i = 0; i < vecTextures.size(); i++) {
            delete this->mapTexture[EType][i];
        }
    }

    this->vecAssetTypes.clear();
    this->mapTexture.clear();
}

TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;

TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new TextureManager();
    }

    return P_SHARED_INSTANCE;
}
