#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "../../../src/core/IPicture.hpp"

namespace Cervantes{

class Picture
{
    public:
        Picture();
        Picture(const std::string& fileName);

        /*  
            Rational for not loading it in constructor: may want a picture object
            before initializing OpenGL. To prevent using any opengl functionality before
            it is fully loaded, separate it into its own function.
        */
        void LoadImage(const std::string& fileName);
        Dimensions getDimensions() const;

        Picture(const Picture&) = delete;
        Picture& operator=(const Picture&) = delete;
        Picture(Picture&& other);
        Picture& operator=(Picture&& other);

         
    private:
        std::unique_ptr<IPicture> m_picture;
        void Bind();

        friend class OpenGLRenderer;
};        

} // end namespace Cervantes


#endif