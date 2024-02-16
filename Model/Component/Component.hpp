#pragma once

#include "../Enum/ComponentType.hpp"

namespace models {
    class GameObject; /* [NOTE] : Forward declaration. This is a Reading Assignment. */
}

namespace components{
    using namespace models;
    class Component{
        protected:
            GameObject* pOwner;
            ComponentType EType;
            std::string strName;
            sf::Time tDeltaTime;
        
        public:
            Component(std::string strName, ComponentType EType);
            virtual ~Component();
        
        public:
            void attachOwner(GameObject* pOwner);
            void detachOwner();
            virtual void perform() = 0;
        
        public:
            GameObject* getOwner();
            ComponentType getType();
            std::string getName();
            sf::Time getTime();
            void setDeltaTime(sf::Time tDeltaTime);
    };
}


