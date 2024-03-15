#include "PlayerBullet.hpp"

using namespace poolables;

PlayerBullet::PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip) : PoolableObject(PoolTag::PLAYER_BULLET, strName, pTexture){
    this->pShip = pShip;
}


void PlayerBullet::initialize(){
    this->centerOrigin();

    BulletMovement* pBulletMovement = new BulletMovement(this->strName + " Movement");
    this->attachComponent(pBulletMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void PlayerBullet::onActivate(){
    this->pSprite->setPosition(this->pShip->getSprite()->getPosition());
}

void PlayerBullet::onRelease(){

}

PoolableObject* PlayerBullet::clone(){
    PoolableObject* pClone = new PlayerBullet(this->strName, new AnimatedTexture(*this->pTexture), this->pShip);

    return pClone;
}
