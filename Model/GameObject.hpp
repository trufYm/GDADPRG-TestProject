#pragma once

#include "AnimatedTexture.hpp"
#include "Component/Component.hpp"
#include "Component/GeneralInput.hpp"
#include "Component/Renderer/Renderer.hpp"

namespace models {
    using namespace components;

    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            AnimatedTexture* pTexture;
            std::vector<Component*> vecComponent;

        public:
            GameObject(std::string strName, AnimatedTexture* pTexture);
            virtual ~GameObject();
        
        public:
            virtual void initialize() = 0;
            virtual void processEvents(sf::Event CEvent);
            virtual void update(sf::Time tDeltaTime);
            virtual void draw(sf::RenderWindow* pWindow);

        public:
            void centerOrigin();
            void attachComponent(Component* pComponent);
            void detachComponent(Component* pComponent);
            Component* findComponentByName(std::string strName);
            std::vector<Component*> getComponents(ComponentType EType);
            float getHalfWidth();
            float getHalfHeight();
            virtual sf::FloatRect getGlobalBounds();
            
        public:
            bool getEnabled();
            void setEnabled(bool bEnabled);
            std::string getName();
            sf::Sprite* getSprite();
            void setFrame(int nFrame);
    };
}
