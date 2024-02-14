#pragma once

#include "AnimatedTexture.hpp"

namespace models {
    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            sf::Texture* pTexture;
            AnimatedTexture* pAnimatedTexture;
            float fSpeed;

        public:
            GameObject(std::string strName, float fSpeed);
            GameObject(std::string strName, float fSpeed, AnimatedTexture* pAnimatedTexture);
        
        /* [TODO][1] :
           Update this class' content based on the lecture
           slides. */
        public:
            virtual void initialize() = 0;
            virtual void processEvents(sf::Event CEvent);
            virtual void update(sf::Time tDeltaTime) = 0;
            virtual void draw(sf::RenderWindow* pWindow);

        protected:
            virtual void processKeyboardInput(sf::Keyboard::Key CKey, bool isPressed) = 0;


        public:
            bool getEnabled();
            std::string getName();
            sf::Sprite* getSprite();
            void setTexture(sf::Texture* pTexture);
            void setFrame(int nFrame);
            float getSpeed();
    };
}
