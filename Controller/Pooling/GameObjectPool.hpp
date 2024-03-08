#pragma once

#include "../../Model/Pooling/PoolableObject.hpp"
#include "../../Model/Enum/PoolTag.hpp"
#include "../Manager/GameObjectManager.hpp"

namespace poolables{
    using namespace managers;
    class GameObjectPool{
        private:
            PoolTag ETag;
            int nPoolSize;
            PoolableObject* pPoolableReference;
            std::vector<PoolableObject*> vecAvailableObject;
            std::vector<PoolableObject*> vecUsedObject;
        
        public:
            GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference);
        
        public:
            void initialize();
            PoolableObject* requestPoolable();
            void releasePoolable(PoolableObject* pPoolableObject);
            void hasAvailable(int nRequestSize);
            void setEnabled(PoolableObject* pPoolableObject, bool bEnabled);
            PoolTag getTag();
    };
}