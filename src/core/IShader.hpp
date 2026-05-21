#ifndef ISHADER_HPP
#define ISHADER_HPP

namespace Cervantes {

class IShader {
    public:
        virtual void loadShader(const std::string& vertFileName, const std::string& fragFileName) = 0;
        virtual void supplyIntUniform(const std::string& uniformName,const std::vector<int>& vals) = 0;
        virtual void Bind() = 0;
        virtual ~IShader() = default;
};

}

#endif