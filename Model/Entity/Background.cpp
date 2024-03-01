#include "Background.hpp"

using namespace entities;

Background::Background(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture){

}

void Background::initialize(){
    BackgroundInput* pBackgroundInput = new BackgroundInput(this->strName + " Input");
    this->attachComponent(pBackgroundInput);

    BackgroundAction* pBackgroundAction = new BackgroundAction(this->strName + " Movement");
    this->attachComponent(pBackgroundAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}