#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    using namespace components;
    class Background : public GameObject {
        /* [TODO] :
           Make [Background] a [GameObject]. */
        public:
            Background(std::string strName, AnimatedTexture* pTexture);
        
        public:
            void initialize();
    };
}
