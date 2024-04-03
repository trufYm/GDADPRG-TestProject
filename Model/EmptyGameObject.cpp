#include "EmptyGameObject.hpp"

using namespace models;

/** @brief
  * The construtor for [EmptyGameObject].
 * @param strName   - The name of the [EmptyGameObject]. */
EmptyGameObject::EmptyGameObject(std::string strName) : GameObject(strName, NULL) {}

/** @brief 
  * An [EmptyGameObject] does NOTHING in its
  * [initialize()]. */
void EmptyGameObject::initialize() {}
