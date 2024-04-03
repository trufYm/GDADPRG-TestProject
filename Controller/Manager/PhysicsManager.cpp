#include "PhysicsManager.hpp"

using namespace managers;
/** @note
  * Collision detection is done here. Collision detection is simply
  * checking whether one [Collider] (i.e. [A]) has entered or exited
  * a collision with another [Collider] (i.e. [B]).
  * 
  * To do this, we loop over the vector of registered [Colliders]. For
  * each iteration, we check if the current element (i.e. [Collider][A])
  * is colliding with any of the OTHER elements in the vector.
  * 
  * So for every element (i.e. [Collider][A]), we loop through the vector
  * again so that we can compare it with all OTHER elements in the vector.
  * Hence, the outer loop serves as [Collider][A], while the inner loop
  * serves as [Collider][B]. */
void PhysicsManager::perform() {
    /* This outer loop goes over every single element in the vector. */
    for(int i = 0; i < this->vecTrackedColliders.size(); i++) {
        /* We store the current element in a local variable called
         * [pColliderA]. */
        Collider* pColliderA = this->vecTrackedColliders[i];

        /* For this current element [pColliderA], we need to check if it is
         * currently colliding with any OTHER element. We start iterating from
         * [i + 1] because ALL [Colliders] before [pColliderA] would have
         * already been checked. */
        for(int j = i + 1; j < this->vecTrackedColliders.size(); j++) {
            Collider* pColliderB = this->vecTrackedColliders[j];

            /* Confirm that [pColliderA] is a different [Collider] from
             * [pColliderB]. Although this condition is NOT needed if you are
             * CERTAIN that ALL [Colliders] have only been registered ONCE
             * (which is the correct thing to do). */
            if(pColliderA != pColliderB) {
                
                /* This condition checks if [pColliderA] has "ENTERED" a collision
                 * with [pColliderB]. When we say "ON COLLISION ENTER", we mean
                 * the following :
                 *      [1] : [pColliderA] and [pColliderB] are CURRENTLY colliding.
                 *      [2] : [pColliderA] and [pColliderB] have NOT collided in the
                 *            previous frame.
                 * 
                 * The reason for condition [2] above is that if [pColliderA] and
                 * [pColliderB] ALREADY collided in the previous frame, then that is
                 * NOT "ON COLLISION ENTER". They did NOT "ENTER" a collision because
                 * they are ALREADY colliding. */
                if(pColliderA->isColliding(pColliderB) &&
                   !pColliderA->hasCollided(pColliderB) &&
                   !pColliderB->hasCollided(pColliderA)) {

                    /* If [pColliderA] and [pColliderB] have "ENTERED" a collision,
                     * we inform them of the collision so that they can keep track
                     * of it (this is important for the [Collider]'s [hasCollided()]
                     * function). */
                    pColliderA->setCollided(pColliderB, true);
                    pColliderB->setCollided(pColliderA, true);

                    /* Then, we call BOTH [Collider]'s [onCollisionEnter()] functions.
                     * This, in turn, calls their listener's [onCollisionEnter()]. */
                    pColliderA->onCollisionEnter(pColliderB);
                    pColliderB->onCollisionEnter(pColliderA);
                }

                /* This condition checks if [pColliderA] has "EXITED" a collision
                 * with [pColliderB]. When we say "ON COLLISION EXIT", we mean
                 * the following :
                 *      [1] : [pColliderA] and [pColliderB] are CURRENTLY NOT colliding.
                 *      [2] : [pColliderA] and [pColliderB] were colliding in the
                 *            previous frame.
                 * 
                 * The reason for condition [2] above is that if [pColliderA] and
                 * [pColliderB] were NOT colliding in the previous frame, then that
                 * means they never even "ENTERED" a collision at all. */
                else if(!pColliderA->isColliding(pColliderB) &&
                        pColliderA->hasCollided(pColliderB) &&
                        pColliderB->hasCollided(pColliderA)) {

                    /* If [pColliderA] and [pColliderB] have "EXITED" a collision,
                     * we inform them of it so that they can stop tracking the collision
                     * (this is important for the [Collider]'s [hasCollided()]
                     * function). */
                    pColliderA->setCollided(pColliderB, false);
                    pColliderB->setCollided(pColliderA, false);

                    /* Then, we call BOTH [Collider]'s [onCollisionExit()] functions.
                     * This, in turn, calls their listener's [onCollisionEnter()]. */
                    pColliderA->onCollisionExit(pColliderB);
                    pColliderB->onCollisionExit(pColliderA);
                }
            }
        }
    }
    
    this->cleanUp();
}

/** @brief 
  * The function that registeres [Colliders].
  * @param pCollider - The [Collider] to be registered. */
void PhysicsManager::trackCollider(Collider* pCollider) {
    pCollider->cleanCollisions();
    this->vecTrackedColliders.push_back(pCollider);
}

/** @brief 
  * The function that unregisteres [Colliders].
  * @param pCollider - The [Collider] to be unregistered. */
void PhysicsManager::untrackCollider(Collider* pCollider) {
    this->vecUntrackedColliders.push_back(pCollider);
}

/** @brief 
  * The function that untracks [Colliders] when necessary. */
void PhysicsManager::cleanUp() {
    Collider* pCollider = NULL;
    int nIndex;

    /* Some [Colliders] may want to automatically STOP detecting
     * collisions after they have collided ONCE. These [Colliders]
     * would have their [bCleanUp] field set to [true] in their
     * listener's [onCollisionEnter()] logic. Meaning, they now wish
     * to be cleaned-up and untracked since they have already met
     * their first collision. */
    for(Collider* pCollider : this->vecTrackedColliders) {
        if(pCollider->getCleanUp())
            this->vecUntrackedColliders.push_back(pCollider);
    }

    /* For the aforementioned [Colliders], we remove them from
     * the [vecTracedCollider] field entirely. */
    for(int i = 0; i < this->vecUntrackedColliders.size(); i++) {
        pCollider = this->vecUntrackedColliders[i];
        nIndex = this->findTrackedCollider(pCollider);

        if(nIndex != -1)
            this->vecTrackedColliders.erase(this->vecTrackedColliders.begin() + nIndex);
    }

    this->vecUntrackedColliders.clear();
}

/** @brief
  * This is a helper function that returns the index of the
  * [pCollider] parameter if it is present in [this] [Collider]'s
  * [vecTrackedColliders] field. Else, it returns [-1].
  * @param pCollider    - The [Collider] to be searched. */
int PhysicsManager::findTrackedCollider(Collider* pCollider) {
    int nIndex = -1;
    for(int i = 0; i < this->vecTrackedColliders.size() && nIndex == -1; i++) {
        if(pCollider == this->vecTrackedColliders[i])
            nIndex = i;
    }

    return nIndex;
}

/* * * * * * * * * * * * * * * * * * * * * 
 *       SINGLETON-RELATED CONTENT       * 
 * * * * * * * * * * * * * * * * * * * * */
PhysicsManager* PhysicsManager::P_SHARED_INSTANCE = NULL;

PhysicsManager::PhysicsManager(std::string strName) : Component(strName, ComponentType::SCRIPT) {}
PhysicsManager::PhysicsManager(const PhysicsManager& CObject) : Component(CObject.strName, ComponentType::SCRIPT) {}

PhysicsManager* PhysicsManager::getInstance() {
    return P_SHARED_INSTANCE;
}

void PhysicsManager::initialize(std::string strName, GameObject* pParent) {
    P_SHARED_INSTANCE = new PhysicsManager(strName);
    pParent->attachComponent(P_SHARED_INSTANCE);
}

void PhysicsManager::destroy() {
    delete P_SHARED_INSTANCE;
}
