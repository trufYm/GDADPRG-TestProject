#include "Game.hpp"

using namespace controllers;

//Constructors
Game::Game() : CWindow(sf::VideoMode(500, 500), "EMMANUEL JOHN TAYLAN"){
    //this->CWindow = sf::RenderWindow(sf::VideoMode(200, 200), "EMMANUEL JOHN TAYLAN");
    
    sf::Texture CTexture;
    if(!CTexture.loadFromFile("View/Image/akame.png")){
        std::cout << "ERROR" << std::endl;
    }

    this->CEntity.setTexture(CTexture);
}

//Methods
void Game::run(){
    while (this->CWindow.isOpen()) {
        this->processEvents();
        this->update();
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

void Game::update() {

}

void Game::render() {
    this->CWindow.clear();
    this->CWindow.draw(*this->CEntity.getSprite());
    this->CWindow.display();
}

void Game::processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed) {
    switch (CKey) {
        case sf::Keyboard::A:
            this->CEntity.getSprite()->move(-5.0f, 0);
            break;
        case sf::Keyboard::D:
            this->CEntity.getSprite()->move(5.0f, 0);
            break;

    }
}