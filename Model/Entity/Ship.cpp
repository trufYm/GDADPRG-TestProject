#include "Ship.hpp"

using namespace entities;

Ship::Ship(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->CNormalColour = sf::Color(0, 0, 0, 255);
    this->bTopBounds = false;
    this->bLeftBounds = false;
    this->bBottomBounds = false;
    this->bRightBounds = false;
}

void Ship::initialize() {
    this->centerOrigin();
    this->pSprite->setPosition(90.0f, 210.0f);
    this->pSprite->setColor(this->CNormalColour);

    ShipInput* pInput = new ShipInput(this->strName + " Input");
    this->attachComponent(pInput);

    ShipControls* pControls = new ShipControls(this->strName + " Controls");
    this->attachComponent(pControls);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

    /** @todo
      * Attach the [Collider] component below by doing the
      * following :
      *     [1] Create a [Collider] object pointer.
      *     [2] Assign the [Collider] object's listener to
      *         this class (i.e. passing [this] to the [Collider]'s
      *         [assignListener()] function.).
      *     [3] Attach the [Collider] component.
      *     [4] Track it using the [PhysicsManager] (i.e. using
      *         the [trackCollider()] method.). */
    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);

    PhysicsManager::getInstance()->trackCollider(pCollider);
}

/** @brief 
  * When [this] [Ship] collides with any of the [Borders], it
  * simply sets the respective flag to [true]. Refer to the
  * [ShipControls] class to know how this prevents the [Ship]
  * from moving past the [Borders].
  * @param pGameObject  - The [GameObject] that [this] collided
  *                       with. */
void Ship::onCollisionEnter(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border")
        this->bTopBounds = true;

    if(pGameObject->getName() == "Left Border")
        this->bLeftBounds = true;

    if(pGameObject->getName() == "Bottom Border")
        this->bBottomBounds = true;

    if(pGameObject->getName() == "Right Border")
        this->bRightBounds = true;
}

/** @brief 
  * When [this] [Ship] stops colliding with any of the [Borders],
  * it simply sets the respective flag to [false]. Refer to the
  * [ShipControls] class to know how this prevents the [Ship]
  * from moving past the [Borders].
  * @param pGameObject  - The [GameObject] that [this] exited
  *                       collision with. */
void Ship::onCollisionExit(GameObject* pGameObject) {
    if(pGameObject->getName() == "Top Border")
        this->bTopBounds = false;
    
    if(pGameObject->getName() == "Left Border")
        this->bLeftBounds = false;
    
    if(pGameObject->getName() == "Bottom Border")
        this->bBottomBounds = false;
    
    if(pGameObject->getName() == "Right Border")
        this->bRightBounds = false;
}

bool Ship::getTopBounds() {
    return this->bTopBounds;
}

bool Ship::getLeftBounds() {
    return this->bLeftBounds;
}

bool Ship::getBottomBounds() {
    return this->bBottomBounds;
}

bool Ship::getRightBounds() {
    return this->bRightBounds;
}
