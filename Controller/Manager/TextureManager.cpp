#include "TextureManager.hpp"

using namespace managers;

void TextureManager::loadAll() {
    std::cout << "All Loaded!" << std::endl;

    sf::Texture* pTexture = new sf::Texture();

    if(!pTexture->loadFromFile("View/Image/donpersimmon.png"))
        std::cout << "ERROR" << std::endl;
    
    //Dictionary - string value pair -> give string return vector
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/akame.png");
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EKey){
    return this->mapTexture[EKey];
} 

sf::Texture* TextureManager::getTextureAt(AssetType EKey, int nFrame){
    return this->mapTexture[EKey][nFrame];
}

TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;

TextureManager::TextureManager() {}
TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    if(P_SHARED_INSTANCE == NULL){
        P_SHARED_INSTANCE = new TextureManager();
    }

    return P_SHARED_INSTANCE;
}