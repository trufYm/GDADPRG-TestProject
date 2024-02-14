#include "Game.hpp"

using namespace controllers;

//Constructors
Game::Game() : CWindow(sf::VideoMode(800, 500), "EMMANUEL JOHN TAYLAN"){
    //this->CWindow = sf::RenderWindow(sf::VideoMode(200, 200), "EMMANUEL JOHN TAYLAN");
    TextureManager::getInstance()->loadAll();

    /*Player* pEntity = new Player("Player");
    pEntity->setTexture(TextureManager::getInstance()->getTextureAt(AssetType::PLAYER, 0));
    GameObjectManager::getInstance()->addObject(pEntity);*/

    AnimatedTexture* pTexture = new AnimatedTexture(AssetType::PLAYER, TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pEntity = new Player("Player", pTexture);
    GameObjectManager::getInstance()->addObject(pEntity);
}

//Methods
void Game::run(){
    sf::Clock CClock = sf::Clock();
    sf::Time tTimePerFrame = sf::seconds(1.0f / 60.0f);
    sf::Time tTimeSinceLastUpdate = sf::Time::Zero;

    this->CWindow.setFramerateLimit(60.0f);

    while (this->CWindow.isOpen()) {
        tTimeSinceLastUpdate += CClock.restart();

        while(tTimeSinceLastUpdate > tTimePerFrame) {
            tTimeSinceLastUpdate -= tTimePerFrame;
            this->processEvents();
            this->update(tTimePerFrame);
        }
        this->render();
    }
}

void Game::processEvents() {
    sf::Event CEvent;
        while (this->CWindow.pollEvent(CEvent)) {
            switch(CEvent.type) {
                case sf::Event::Closed:
                    this->CWindow.close();
                    break;
                
                default:
                    GameObjectManager::getInstance()->processEvents(CEvent);
                    break;
                
            }
        }
}

void Game::update(sf::Time tDeltaTime) {
    GameObjectManager::getInstance()->update(tDeltaTime);
}

void Game::render() {
    this->CWindow.clear();
    GameObjectManager::getInstance()->draw(&this->CWindow);
    this->CWindow.display();
}
