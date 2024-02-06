#pragma once

/* * * * * [TODO][1] * * * * *
 Add content based on the Game
 Object class diagram shown in
 the lecture slides.
 * * * * * * * * * * * * * * */

namespace models {
    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            sf::Texture* pTexture;
            float fSpeed;

        public:
            GameObject(std::string strName, float fSpeed);
        
        public:
            bool getEnabled();
            std::string getName();
            sf::Sprite* getSprite();
            void setTexture(sf::Texture* pTexture);
            float getSpeed();
    };
}
