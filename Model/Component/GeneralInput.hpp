#pragma once

#include "../Enum/ComponentType.hpp"
#include "Component.hpp"

namespace components {
    class GeneralInput : public Component {
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
