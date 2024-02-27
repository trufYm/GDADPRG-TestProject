#pragma once

#include "../../Model/Enum/AssetType.hpp"

namespace managers{
    class TextureManager{
        private:
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;

        public:
            void loadAll();
            void loadMainMenu();
            void loadGame();
            void clearAll();


            std::vector<sf::Texture*> getTexture(AssetType EKey);
            sf::Texture* getTextureAt(AssetType EKey, int nFrame);
        
        private:
            static TextureManager* P_SHARED_INSTANCE;

        private:
            TextureManager();
            TextureManager(TextureManager const&);
            TextureManager& operator = (const TextureManager&);

        public:
            static TextureManager* getInstance();
    };
}