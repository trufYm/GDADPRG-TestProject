#include "BulletMovement.hpp"

using namespace components;

BulletMovement::BulletMovement(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 0.01f;
    this->fTicks = 0.0f;
    this->fSpeed = 350.0f;
}

void BulletMovement::perform() {
    PoolableObject* pPoolableOwner = (PoolableObject*)this->pOwner;
    PlayerBullet* pBullet = (PlayerBullet*)this->pOwner;

    if(pPoolableOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->fTicks += this->tDeltaTime.asSeconds();

        if(this->fTicks > this->fFrameInterval) {
            this->fTicks = 0.0f;
            this->pOwner->getSprite()->move(this->fSpeed * this->tDeltaTime.asSeconds(), 0.0f);

            float fHalfWidth = this->pOwner->getSprite()->getGlobalBounds().width / 2.0f;

            //if(pBullet->getRightBounds()){
            //    ObjectPoolManager::getInstance()->getPool(pPoolableOwner->getTag())->releasePoolable(pPoolableOwner);
            //}


            if(this->pOwner->getSprite()->getPosition().x >= (SCREEN_WIDTH + fHalfWidth) || pBullet->getRightBounds()) {
                ObjectPoolManager::getInstance()->getPool(pPoolableOwner->getTag())->releasePoolable(pPoolableOwner);
            }

            
        }
    }
}
