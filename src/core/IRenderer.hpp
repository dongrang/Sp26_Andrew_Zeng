#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include "Cervantes/core/Picture.hpp"
#include "Cervantes/core/Shader.hpp"

namespace Cervantes {

class IRenderer {
    public:
        virtual void draw(Picture& pic, int xCoord,int yCoord,Shader& shader) = 0;
        virtual void screenClear() = 0;
        virtual ~IRenderer() = default;   
         
        private:
};

} // end namespace Cervantes

#endif