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
            bool hasAvailable(int nRequestSize);
            std::vector<PoolableObject*> requestPoolableBatch(int nRequestSize);
            
        public:
            void setEnabled(PoolableObject* pPoolableObject, bool bEnabled);
            PoolTag getTag();
    };
}