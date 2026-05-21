#include "PictureOpenGL.hpp"

#include <glad/gl.h>
#include <stb_image.h>

namespace Cervantes {

    PictureOpenGL::PictureOpenGL()
    {
    }

    PictureOpenGL::PictureOpenGL(const std::string& fileName)
    {
                //// Textures /////

        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        // these parameters tell open gl how to handle the texture being a different size
        // from the rectangle that we create 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // handles the different sizes
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width,height,nrChannels;
        
        stbi_set_flip_vertically_on_load(true);
        // unsigned char means an array of unsigned 1 byte integers
        unsigned char* image_data = stbi_load(fileName.c_str(), &width,&height, &nrChannels, 0);
        if(image_data)
        {
            GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,GL_UNSIGNED_BYTE,image_data);
            m_dimensions = { static_cast<std::uint32_t>(width), 
                    static_cast<std::uint32_t>(height) };
            // remember, mipmap are the smaller copies of our image
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "Failed to load texture." << std::endl;
        }

        // releases memory
        stbi_image_free(image_data);
    }

    void PictureOpenGL::LoadImage(const std::string& fileName)
    {
        if(m_texture)
        {
            glDeleteTextures(1,&m_texture);
            m_texture = 0;
        }
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);

        // these parameters tell open gl how to handle the texture being a different size
        // from the rectangle that we create 
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // handles the different sizes
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width,height,nrChannels;
        
        stbi_set_flip_vertically_on_load(true);
        // unsigned char means an array of unsigned 1 byte integers
        unsigned char* image_data = stbi_load(fileName.c_str(), &width,&height, &nrChannels, 0);
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        if(image_data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,GL_UNSIGNED_BYTE,image_data);
            // remember, mipmap are the smaller copies of our image
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "Failed to load texture." << std::endl;
        }

        // releases memory
        stbi_image_free(image_data);
    }

    Dimensions PictureOpenGL::getDimensions() const
    {
        return m_dimensions;
    }

    void PictureOpenGL::Bind()
    {
        glBindTexture(GL_TEXTURE_2D, m_texture);
    }

    PictureOpenGL::~PictureOpenGL()
    {
        glDeleteTextures(1,&m_texture);
    }


}