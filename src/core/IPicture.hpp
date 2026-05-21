#ifndef IPICTURE_HPP
#define IPICTURE_HPP

#include "Cervantes/core/types.hpp"

namespace Cervantes{

class IPicture{
    public:
        virtual void LoadImage(const std::string& fileName) = 0;
        virtual Dimensions getDimensions() const = 0;
        virtual void Bind() = 0;
        virtual ~IPicture() = default;
};

}

#endif 