#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Shader.hpp"
#include "Picture.hpp"
#include "Unit.hpp"
#include "Screen.hpp"
#include "../../../src/core/IRenderer.hpp"

namespace Cervantes{

class Renderer {
    public:

        static void init();
        static std::unique_ptr<Renderer>& get();

        void draw(Picture& pic, int xCoord, int yCoord);
        void draw(Picture& pic, int xCoord, int yCoord,Shader& shader);
        void draw(Unit& unit);
        void draw(Unit& unit, Shader& shader); 

        void draw(Background& background);
        void draw(Background& background, Shader& shader);
        void draw(Ui& ui); 
        void draw(Ui& ui, Shader& shader); 

        void screenClear();
    private:
        std::unique_ptr<IRenderer> m_renderer;
        Shader mDefaultShader;
        Renderer();
        inline static std::unique_ptr<Renderer> m_instance;
};


}

#endif