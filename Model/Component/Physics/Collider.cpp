#include "Collider.hpp"

using namespace components;

/** @brief The constructor for [Collider].
  * @param strName   - The name of the [Collider]. */
Collider::Collider(std::string strName) : Component(strName, ComponentType::PHYSICS) {
    this->pListener = NULL;
    this->COffset = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f);
    this->vecCollided = {};
    this->bCleanUp = false;
}

/** @brief
  * [Collider] really has NO default implementation for
  * the [perform()] function. */
void Collider::perform() {}

/** @brief 
  * This function returns [true] if [this] [Collider] and the
  * [pCollider] parameter are currently touching bounds.
  * @param pCollider    - The [Collider] to be checked against.
  * @return true 
  * @return false */
bool Collider::isColliding(Collider* pCollider) {
    sf::FloatRect CBoundsA = this->getGlobalBounds();
    sf::FloatRect CBoundsB = pCollider->getGlobalBounds();

    return CBoundsA.intersects(CBoundsB);
}

/** @brief 
  * This function returns [true] if [this] [Collider] has
  * previously collided with the [pCollider] parameter. This
  * can be surmised by checking if [pCollider] is present
  * in [this] [Collider]'s [vecCollided] field.
  * @param pCollider    - The [Collider] to be checked against.
  * @return true 
  * @return false */
bool Collider::hasCollided(Collider* pCollider) {
    if(this->findCollider(pCollider) != -1)
        return true;

    return false;
}

/** @brief 
  * This function adds or removes the [pCollider] parameter
  * from [this] [Collider]'s [vecCollided] field. It is added
  * to the vector if the [bCollided] parameter is [true].
  * Else, it is removed.
  * @param pCollider    - The [Collider] to be tracked or
  *                       untracked.
  * @param bCollided    - The flag to denote whether a [Collider]
  *                       will be tracked or untracked. */
void Collider::setCollided(Collider* pCollider, bool bCollided) {
    if(bCollided)
        this->vecCollided.push_back(pCollider);

    else {
        int nIndex = this->findCollider(pCollider);

        if(nIndex != -1)
            this->vecCollided.erase(this->vecCollided.begin() + nIndex);
    }
}

/** @brief 
  * This is a helper function that returns the index of the
  * [pCollider] parameter if it is present in [this] [Collider]'s
  * [vecCollided] field. Else, it returns [-1].
  * @param pCollider    - The [Collider] to be searched.
  * @return int */
int Collider::findCollider(Collider* pCollider) {
    int nIndex = -1;

    for(int i = 0; i < this->vecCollided.size() && nIndex == -1; i++) {
        if(pCollider == this->vecCollided[i])
            nIndex = i;
    }

    return nIndex;
}

/** @brief 
  * This is a helper function that clears ALL previous collisions
  * in [this] [Collider]. This is used by [PhysicsManager] when
  * first registering a [Collider]. */
void Collider::cleanCollisions() {
    this->vecCollided.clear();
}

/** @brief 
  * This function calls [this] [Collider]'s listener's
  * [onCollisionEnter()] function. It notifies its listener that
  * it has collided with the [pCollider] parameter's owner. The
  * listener may now handle the collision as it sees fit.
  * @param pCollider    - The [Collider] that was collided with. */
void Collider::onCollisionEnter(Collider* pCollider) {
    if(this->pListener != NULL) {
        this->pListener->onCollisionEnter(pCollider->getOwner());
    }
}

/** @brief
  * This function calls [this] [Collider]'s listener's
  * [onCollisionExit()] function. It notifies its listener that
  * it has exited the collision with the [pCollider] parameter's
  * owner. The listener may now handle this as it sees fit.
  * @param pCollider    - The [Collider] that was un-collided with. */
void Collider::onCollisionExit(Collider* pCollider) {
    if(this->pListener != NULL) {
        this->pListener->onCollisionExit(pCollider->getOwner());
    }
}

/** @brief 
  * This is basically a setter for the [pListener] field. This
  * is called upon the creation and attachment of [this] [Collider]
  * to its owner.
  * @param pListener    - The value to be assigned. */
void Collider::assignListener(CollisionListener* pListener) {
    this->pListener = pListener;
}

/** @brief 
  * The setter for the [COffset] field.
  * @param COffset  - The value to be set. */
void Collider::setOffset(sf::FloatRect COffset) {
    this->COffset = COffset;
}

/** @brief 
  * The getter for the [bCleanUp] field. */
bool Collider::getCleanUp() {
    return this->bCleanUp;
}

/** @brief 
  * The setter for the [bCleanUp] field.
  * @param bCleanUp  - The value to be set. */
void Collider::setCleanUp(bool bCleanUp) {
    this->bCleanUp = bCleanUp;
}

/** @brief 
  * This is mainly used in the [isColliding()] function. A
  * [Collider]'s bounds is basically its owner's bounds
  * PLUS any offsets added to the [Collider] (denoted by the
  * [COffset] field).
  * @return sf::FloatRect */
sf::FloatRect Collider::getGlobalBounds() {
    sf::FloatRect CTransform = this->getOwner()->getGlobalBounds();
    
    CTransform.left = CTransform.left + this->COffset.left;
    CTransform.top = CTransform.top + this->COffset.top;
    CTransform.width = CTransform.width + this->COffset.width;
    CTransform.height = CTransform.height + this->COffset.height;

    return CTransform;
}
