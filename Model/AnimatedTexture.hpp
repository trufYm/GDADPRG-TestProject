#pragma once

#include "Enum/AssetType.hpp"

namespace models{
    class AnimatedTexture{
        private:
            AssetType EType;
            std::vector<sf::Texture*> vecFrames;
            int nCurrentFrame;
        
        public:
            AnimatedTexture(AssetType EType, std::vector<sf::Texture*> vecFrames);
        
        public:
            void incrementFrame();
        
        public:
            sf::Texture* getFrame();
            void setCurrentFrame(int nCurrentFrame);
    };
}