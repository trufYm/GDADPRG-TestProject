#include "Game.hpp"

using namespace controllers;

//Constructors
Game::Game() : CWindow(sf::VideoMode(243, 238), "EMMANUEL JOHN TAYLAN"){
    //this->CWindow = sf::RenderWindow(sf::VideoMode(200, 200), "EMMANUEL JOHN TAYLAN");
    
    sf::Texture CTexture;
    if(!CTexture.loadFromFile("./View/Image/akame.png")){
        std::cout << "ERROR" << std::endl;
    }
    else {
        this->CEntity = new models::GameObject(CTexture);
    }
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
            }
        }
}

void Game::update() {
    if(bCloseWindow){
        bCloseWindow = false;
        CWindow.close();
    }
}

void Game::render() {
    this->CWindow.clear();
    this->CEntity->renderTo(&this->CWindow);
    this->CWindow.display();
}