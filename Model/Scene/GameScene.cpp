#include "GameScene.hpp"

using namespace scenes;

GameScene::GameScene() : Scene(SceneTag::GAME_SCENE) {}

void GameScene::onLoadResources() {
    TextureManager::getInstance()->loadGame();
}

void GameScene::onLoadObjects() {
    this->createNullObjects();
    this->createBackground();
    this->createShip();
    this->createObjectPools();
    this->createBorders();
}

void GameScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll();
}

void GameScene::createNullObjects() {
    EmptyGameObject* pHolder = new EmptyGameObject("Physics Manager Holder");
    PhysicsManager::initialize("Physics Manager", pHolder);
    GameObjectManager::getInstance()->addObject(pHolder);
}

void GameScene::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::GAME_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    this->registerObject(pBackground);
}

void GameScene::createShip() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHIP));
    Ship* pShip = new Ship("Ship", pTexture);
    this->registerObject(pShip);
}

void GameScene::createObjectPools() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BULLET));
    Ship* pShip = (Ship*)GameObjectManager::getInstance()->findObjectByName("Ship");
    GameObjectPool* pBulletPool = new GameObjectPool(PoolTag::PLAYER_BULLET, 3, new PlayerBullet("Bullet", pTexture, pShip));
    pBulletPool->initialize();
    ObjectPoolManager::getInstance()->registerObjectPool(pBulletPool);
}

/** @brief
  * This function creates the TOP, LEFT, BOTTOM, and RIGHT
  * [Borders] for this [Scene]. */
void GameScene::createBorders() {
    /** @note
      * The sizes of the [Border] objects are as follows :
      *     - TOP       SCREEN_WIDTH by [24]
      *     - LEFT      [24] by SCREEN_HEIGHT
      *     - BOTTOM    SCREEN_WIDTH by [36]
      *     - RIGHT     [24] by SCREEN_HEIGHT
      * 
      * You can figure out their correct positions based on
      * the SCREEN (i.e. SCREEN_WIDTH and SCREEN_HEIGHT) and
      * [Border] sizes. */
    int fSize = 24.0f;
    int fOffset = 12.0f;

    /** @note
      * The TOP BORDER creation is provided below. */
    GameObjectManager::getInstance()->addObject(new Border("Top Border",
                                                           sf::FloatRect(0.0f, 0.0f, SCREEN_WIDTH, fSize)));

    /** @todo
      * Create the LEFT BORDER. You MUST give it the
      * name of "Left Border" for the [Ship] object's
      * compatibility. */
    GameObjectManager::getInstance()->addObject(new Border("Left Border", 
                                                          sf::FloatRect(0.0f, 0.0f, fSize, SCREEN_HEIGHT)));

    /** @todo
      * Create the BOTTOM BORDER. You MUST give it the
      * name of "Bottom Border" for the [Ship] object's
      * compatibility. */
    GameObjectManager::getInstance()->addObject(new Border("Bottom Border", 
                                                          sf::FloatRect(0.0f, SCREEN_HEIGHT - (fSize + fOffset), SCREEN_WIDTH, fSize + fOffset)));

    /** @todo
      * Create the RIGHT BORDER. You MUST give it the
      * name of "Right Border" for the [Ship] object's
      * compatibility. */
    GameObjectManager::getInstance()->addObject(new Border("Right Border", 
                                                          sf::FloatRect(SCREEN_WIDTH - fSize, 0.0f, fSize, SCREEN_HEIGHT))); //
}
