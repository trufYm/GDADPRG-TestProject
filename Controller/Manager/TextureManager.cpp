#include "TextureManager.hpp"

using namespace managers;

void TextureManager::loadAll() {
    std::cout << "All Loaded!" << std::endl;
}

std::vector<sf::Texture*> TextureManager::getTexture(std::string strType){
    std::vector<sf::Texture*> vecEmpty;
    return vecEmpty;
} 

sf::Texture* TextureManager::getTextureAt(std::string strType, int nFrame){
    return NULL;
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