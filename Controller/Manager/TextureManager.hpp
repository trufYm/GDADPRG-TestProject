#pragma once

#include "../../Model/Enum/AssetType.hpp"

namespace managers {
    class TextureManager {
        private:
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;
            std::vector<AssetType> vecAssetTypes;

        public:
            void loadMainMenu();
            void loadGame();
            void unloadAll();

            std::vector<sf::Texture*> getTexture(AssetType EType);
            sf::Texture* getTextureAt(AssetType EType, int nFrame);

        private:
            static TextureManager* P_SHARED_INSTANCE;
        
        private:
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);

        public:
            static TextureManager* getInstance();
    };
}