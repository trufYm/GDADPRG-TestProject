#include "Game.hpp"

using namespace controllers;

//Constructors
Game::Game() : CWindow(sf::VideoMode(800, 440), "EMMANUEL JOHN TAYLAN"){
    SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->registerScene(new GameScene());
    SceneManager::getInstance()->loadScene(SceneTag::MAIN_MENU_SCENE);
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

        SceneManager::getInstance()->checkLoadScene();
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
