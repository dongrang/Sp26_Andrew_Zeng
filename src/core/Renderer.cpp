#include "Cervantes/core/Renderer.hpp"
#include "Cervantes/core/window.hpp"

#include "OpenGLRenderer.hpp"


namespace Cervantes {

Renderer::Renderer()
{
    m_renderer = std::unique_ptr<IRenderer>{ new OpenGLRenderer };
    mDefaultShader.loadShader("assets/shaders/vertex.glsl","assets/shaders/fragment.glsl");
}

void Renderer::init()
{
    if(!m_instance)
    {
        m_instance = std::unique_ptr<Renderer>{new Renderer};
    }
}

std::unique_ptr<Renderer>& Renderer::get()
{
    return m_instance;
}



void Renderer::draw(Picture& pic, int xCoord, int yCoord)
{
    int width = static_cast<int>(Window::get()->getSize().width);
    int height = static_cast<int>(Window::get()->getSize().height);
    mDefaultShader.supplyIntUniform("screenRes", {width,height});
    m_renderer->draw(pic, xCoord, yCoord, mDefaultShader);
}

void Renderer::draw(Picture& pic, int xCoord, int yCoord,Shader& shader)
{
    m_renderer->draw(pic, xCoord, yCoord, shader);
}

void Renderer::draw(Unit& unit)
{
    int width = static_cast<int>(Window::get()->getSize().width);
    int height = static_cast<int>(Window::get()->getSize().height);
    mDefaultShader.supplyIntUniform("screenRes", {width,height});
    m_renderer->draw(unit.mPicture,unit.mXpos,unit.mYpos,mDefaultShader);
}

void Renderer::draw(Unit& unit, Shader& shader)
{
    m_renderer->draw(unit.mPicture,unit.mXpos,unit.mYpos,shader);
}  

void Renderer::screenClear()
{
    m_renderer->screenClear();
}

} // end namespace Cervantes