#include "PlayerBullet.hpp"

using namespace poolables;

PlayerBullet::PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip) : PoolableObject(PoolTag::PLAYER_BULLET, strName, pTexture){
    this->pShip = pShip;
}


void PlayerBullet::initialize(){

}

void PlayerBullet::onActivate(){

}

void PlayerBullet::onRelease(){

}

PoolableObject* PlayerBullet::clone(){
    PoolableObject* pClone = new PlayerBullet(this->strName, new AnimatedTexture(*this->pTexture), this->pShip);

    return pClone;
}
