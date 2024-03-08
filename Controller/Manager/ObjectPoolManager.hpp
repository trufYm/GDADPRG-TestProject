#pragma once

namespace managers{
    class ObjectPoolManager{
        private:

        public:


        /* * * * * * * * * * * * * * * * * * * * * 
         *       SINGLETON-RELATED CONTENT       * 
         * * * * * * * * * * * * * * * * * * * * */
        private:
            static ObjectPoolManager* P_SHARED_INSTANCE;
        
        private:
            ObjectPoolManager();
            ObjectPoolManager(ObjectPoolManager const&);
            ObjectPoolManager& operator = (const ObjectPoolManager&);
        
        public:
            static ObjectPoolManager* getInstance();
    };
}