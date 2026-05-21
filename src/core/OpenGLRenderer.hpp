#ifndef OPENGL_RENDERER_HPP
#define OPENGL_RENDERER_HPP

#include "IRenderer.hpp"

namespace Cervantes {

class OpenGLRenderer : public IRenderer{
    public:

        OpenGLRenderer();
        void draw(Picture& pic, int xCoord,int yCoord,Shader& shader) override;
        void screenClear() override;
    private:

};

} // end namespace Cervantes
#endif