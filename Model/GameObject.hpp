#pragma once

namespace models {
    class GameObject {
        //Field
        private:
            sf::Texture CTexture;
            sf::Sprite imgSprite;
            float fSpeed;
            bool isMovingLeft;
            bool isMovingRight;
        
        //Constructors
        public:
            GameObject();
        
        //Methods
            void renderTo(sf::RenderWindow* window);

        //Getters & Setters
        public:
            void setTexture(sf::Texture CTexture);
            sf::Sprite* getSprite();

            float getSpeed();
            
            bool getMovingLeft();
            void setMovingLeft(bool isMovingLeft);
            
            bool getMovingRight();
            void setMovingRight(bool isMovingRight);
    };
}