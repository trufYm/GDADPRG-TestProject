#pragma once

#include "Enum/AssetType.hpp"

namespace models{
    class AnimatedTexture{
        private:
            std::vector<sf::Texture*> vecFrames;
            int nCurrentFrame;
        
        public:
            AnimatedTexture(std::vector<sf::Texture*> vecFrames);
        
        public:
            void incrementFrame();
        
        public:
            sf::Texture* getFrame();
            void setCurrentFrame(int nCurrentFrame);
    };
}