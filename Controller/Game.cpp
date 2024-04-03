#include "Game.hpp"

using namespace controllers;

Game::Game() : CWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "EMMANUEL JOHN R. TAYLAN") {
    SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->registerScene(new GameScene());

    SceneManager::getInstance()->loadScene(SceneTag::GAME_SCENE);
}

void Game::run() {
    sf::Clock CClock = sf::Clock();
    sf::Time tLastUpdate = sf::Time::Zero;
    sf::Time tTimePerFrame = sf::seconds(1.0f / FRAME_RATE_LIMIT);

    while(this->CWindow.isOpen()) {
        this->processEvents();
        tLastUpdate += CClock.restart();

        while(tLastUpdate > tTimePerFrame) {
            tLastUpdate -= tTimePerFrame;
            this->update(tTimePerFrame);
        }
        
        SceneManager::getInstance()->checkLoadScene();
        this->render();
    }
}

void Game::processEvents() {
    sf::Event CEvent;
    while(this->CWindow.pollEvent(CEvent)) {
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
