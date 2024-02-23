#pragma once

#include "../Component.hpp"

namespace renderers{
    using namespace components;
    class Renderer : public Component{
        private:
            sf::RenderWindow* pWindow;
            std::vector<sf::Drawable*> vecDrawables;

        public:
            Renderer(std::string strName);
        
        public:
            void assignTargetWindow(sf::RenderWindow* pWindow);
            void assignDrawable(sf::Drawable* pDrawable);
    };
}