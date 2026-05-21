#ifndef PICTUREOPENGL_HPP
#define PICTUREOPENGL_HPP

#include "IPicture.hpp"

namespace Cervantes {

class PictureOpenGL : public IPicture {
    public:

        PictureOpenGL();
        PictureOpenGL(const std::string& fileName);
        
        void LoadImage(const std::string& fileName) override;
        Dimensions getDimensions() const override;
        void Bind() override;
        ~PictureOpenGL() override;

        PictureOpenGL(const PictureOpenGL&) = delete;
        PictureOpenGL& operator=(const PictureOpenGL&) = delete;
        PictureOpenGL(PictureOpenGL&& other) noexcept;
        PictureOpenGL& operator=(PictureOpenGL&&) noexcept;
    private:

        unsigned int m_texture{0};
        Dimensions m_dimensions{0,0};
};

} // end namespace Cervantes
#endif