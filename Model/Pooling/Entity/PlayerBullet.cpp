#include "PlayerBullet.hpp"

using namespace poolables;

PlayerBullet::PlayerBullet(std::string strName, AnimatedTexture* pTexture, Ship* pShip) : PoolableObject(PoolTag::PLAYER_BULLET, strName, pTexture) {
    this->pShip = pShip;
}

void PlayerBullet::initialize() {
    this->centerOrigin();

    BulletMovement* pMovement = new BulletMovement(this->strName + " Movement");
    this->attachComponent(pMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);
}

void PlayerBullet::onActivate() {
    this->pSprite->setPosition(this->pShip->getSprite()->getPosition().x + this->pShip->getHalfWidth(), this->pShip->getSprite()->getPosition().y);
}

void PlayerBullet::onRelease() {}

PoolableObject* PlayerBullet::clone() {
    PoolableObject* pClone = new PlayerBullet(this->strName, new AnimatedTexture(*this->pTexture), this->pShip);
    return pClone;
}

void PlayerBullet::onCollisionEnter(GameObject* pGameObject){
    if(pGameObject->getName() == "Top Border")
        this->bTopBounds = true;

    if(pGameObject->getName() == "Left Border")
        this->bLeftBounds = true;

    if(pGameObject->getName() == "Bottom Border")
        this->bBottomBounds = true;

    if(pGameObject->getName() == "Right Border")
        this->bRightBounds = true;
}

void PlayerBullet::onCollisionExit(GameObject* pGameObject){
    if(pGameObject->getName() == "Top Border")
        this->bTopBounds = false;
    
    if(pGameObject->getName() == "Left Border")
        this->bLeftBounds = false;
    
    if(pGameObject->getName() == "Bottom Border")
        this->bBottomBounds = false;
    
    if(pGameObject->getName() == "Right Border")
        this->bRightBounds = false;
}

bool PlayerBullet::getTopBounds(){
    return this->bTopBounds;
}

bool PlayerBullet::getLeftBounds(){
    return this->bLeftBounds;
}

bool PlayerBullet::getBottomBounds(){
    return this->bBottomBounds;
}

bool PlayerBullet::getRightBounds(){
    return this->bRightBounds;
}