#include "AnimatedTexture.hpp"

using namespace models;

AnimatedTexture::AnimatedTexture(std::vector<sf::Texture*> vecFrames){
    this->vecFrames = vecFrames;
    this->nCurrentFrame = 0;
}
        

void AnimatedTexture::incrementFrame(){
    this->setCurrentFrame(this->nCurrentFrame + 1);
}

sf::Texture* AnimatedTexture::getFrame(){
    return this->vecFrames[this->nCurrentFrame];
}

void AnimatedTexture::setCurrentFrame(int nCurrentFrame){
    if(nCurrentFrame > this->vecFrames.size() || nCurrentFrame < 0)
        this->nCurrentFrame = 0;
    
    else
        this->nCurrentFrame = nCurrentFrame;
}