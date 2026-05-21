#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include "Picture.hpp"

namespace Cervantes{

class Ui{
    public:
        Ui(const std::string& fileName);
        Dimensions getDimensions() const;
    private:
        Picture picture_;
        int xCoord_{ 0 };
        int yCoord_{ 0 };
        friend class Renderer;
};

class Background{
    public:
        Background(const std::string& fileName);
        Dimensions getDimensions() const;
    private:
        Picture picture_;
        friend class Renderer;
};


} // end namespace Cervantes

#endif