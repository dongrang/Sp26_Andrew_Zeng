#include "Cervantes/core/Picture.hpp"
#include "PictureOpenGL.hpp"

namespace Cervantes
{
    /* 
        a swap point for possible future implementations of vulkan,
        (both constructors)
    */
    Picture::Picture()
    {
        m_picture = std::make_unique<PictureOpenGL>();
    }

    Picture::Picture(const std::string& fileName)
    {
        m_picture = std::make_unique<PictureOpenGL>(fileName);
    }

    Picture::Picture(Picture&& other)
    {
        m_picture = std::move(other.m_picture);
    }
    Picture& Picture::operator=(Picture&& other)
    {
        m_picture = std::move(other.m_picture);
        return *this;
    }
    void Picture::LoadImage(const std::string& fileName)
    {
        m_picture->LoadImage(fileName);
    }

    Dimensions Picture::getDimensions() const
    {
        return m_picture->getDimensions();
    }

    void Picture::Bind()
    {
        m_picture->Bind();
    }
}