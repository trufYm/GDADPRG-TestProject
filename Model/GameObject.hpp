#pragma once

#include "SFML/Graphics.hpp"

namespace models {
    class GameObject {
        //Field
        private:
            sf::Texture CTexture;
            sf::Sprite imgSprite;
        
        //Constructors
        public:
            GameObject();
        
        //Methods
            void renderTo(sf::RenderWindow* window);

        //Getters & Setters
        public:
            void setTexture(sf::Texture CTexture);
            sf::Sprite* getSprite();
    };
}