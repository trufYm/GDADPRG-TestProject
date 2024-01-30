#pragma once

namespace managers{
    class TextureManager{
        private:
            std::unordered_map<std::string, std::vector<sf::Texture*>> mapTexture;

        public:
            void loadAll();
            std::vector<sf::Texture*> getTexture(std::string strType);
            sf::Texture* getTextureAt(std::string strType, int nFrame);
        
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