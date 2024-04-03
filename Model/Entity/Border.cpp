#include "Border.hpp"

using namespace entities;

/** @brief
  * This is the constructor for [Border].
  * @param strName  - The name of the [Border] object.
  * @param CBounds  - A [FloatRect] object containing the bounds,
  *                   which is the (x, y, width, height) values of
  *                   the [Border] object. See the SFML documentation
  *                   for more details. */
Border::Border(std::string strName, sf::FloatRect CBounds) : GameObject(strName, NULL) {
    this->CBounds = CBounds;
}

void Border::initialize() {
    /** @note
      * The [Collider] creation. */
    Collider* pCollider = new Collider(this->strName + " Collider");
    pCollider->assignListener(this);
    this->attachComponent(pCollider);
    PhysicsManager::getInstance()->trackCollider(pCollider);

    /** @note
      * A [Renderer] component is NOT required. However, I made
      * a [RectangleShape] that follows the bounds of the [CBounds]
      * field. This is to help visualize the [Border]'s size and
      * position. Note that this highlight is NOT made to move after
      * initialization.*/
    if(SHOW_COLLIDERS) {        
        sf::RectangleShape* pRectangle = new sf::RectangleShape();
        pRectangle->setSize({this->CBounds.width, this->CBounds.height});
        pRectangle->setPosition({this->CBounds.left, this->CBounds.top});
        pRectangle->setFillColor(sf::Color(255, 0, 0, 150));

        Renderer* pRenderer = new Renderer(this->strName + " Renderer");
        pRenderer->assignDrawable(pRectangle);
        this->attachComponent(pRenderer);
    }
}

void Border::onCollisionEnter(GameObject* pGameObject) {}

void Border::onCollisionExit(GameObject* pGameObject) {}

sf::FloatRect Border::getGlobalBounds() {
    return this->CBounds;
}
