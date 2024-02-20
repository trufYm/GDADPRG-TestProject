#pragma once

#include "Component.hpp"
#include "../Enum/ComponentType.hpp"

namespace components {
    class GeneralInput : public Component{
        protected:
            sf::Event CEvent;

        public:
            GeneralInput(std::string strName);
        
        public:
            virtual void perform() = 0;
        
        public:
            void assignEvent(sf::Event CEvent);
    };
}
