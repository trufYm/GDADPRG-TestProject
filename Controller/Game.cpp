#include "Game.hpp"

using namespace controllers;

//Constructors
Game::Game() : CWindow(sf::VideoMode(800, 500), "EMMANUEL JOHN TAYLAN"){
    //this->CWindow = sf::RenderWindow(sf::VideoMode(200, 200), "EMMANUEL JOHN TAYLAN");

    sf::Texture CTexture;
    if(!CTexture.loadFromFile("View/Image/akame.png")){
        std::cout << "ERROR" << std::endl;
    }

    sf::Texture CTex2;
    if(!CTex2.loadFromFile("View/Image/donpersimmon.png")){
        std::cout << "ERROR" << std::endl;
    }

    this->CEntity.setTexture(CTexture);
    this->CDonPer.setTexture(CTex2);

    this->CDonPer.getSprite()->setPosition(100, 100);

    Template::getInstance()->test(); //No work, no instance of template

    TextureManager::getInstance()->loadAll();
    TextureManager::getInstance()->getTexture("hello");
    TextureManager::getInstance()->getTextureAt("hello", 5);
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
                case sf::Event::KeyPressed:
                    processKeyboardInput(CEvent.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    processKeyboardInput(CEvent.key.code, false);
                    break;
            }
        }
}

void Game::update(sf::Time tTimePerFrame) {
    if(this->CEntity.getMovingLeft()){
        this->CEntity.getSprite()->move(-1.0f * this->CEntity.getSpeed() * tTimePerFrame.asSeconds(), 0.0f);
    }

    if(this->CEntity.getMovingRight()){
        this->CEntity.getSprite()->move(1.0f * this->CEntity.getSpeed() * tTimePerFrame.asSeconds(), 0.0f);
    }
    
}

void Game::render() {
    this->CWindow.clear();
    this->CWindow.draw(*this->CEntity.getSprite());
    this->CWindow.draw(*this->CDonPer.getSprite());
    this->CWindow.display();
}

void Game::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed) {
    switch (CKey) {
        case sf::Keyboard::A:
            this->CEntity.setMovingLeft(isPressed);
            break;
        case sf::Keyboard::D:
            this->CEntity.setMovingRight(isPressed);
            break;

    }
}