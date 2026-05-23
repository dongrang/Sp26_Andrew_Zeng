#ifndef TYPES_HPP
#define TYPES_HPP

namespace Cervantes {

struct Dimensions {
    std::uint32_t width{640};
    std::uint32_t height{480};

    Dimensions(std::uint32_t newWidth, std::uint32_t newHeight):width(newWidth),height(newHeight){};
};

} // end namespace Cervantes

#endif