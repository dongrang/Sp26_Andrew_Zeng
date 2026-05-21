#ifndef SHADEROPENGL_HPP
#define SHADEROPENGL_HPP

#include "IShader.hpp"

namespace Cervantes {

class ShaderOpenGL : public IShader {
    public:
        ShaderOpenGL();
        ShaderOpenGL(const std::string& vertFileName, const std::string& fragFileName);
        void loadShader(const std::string& vertFileName, const std::string& fragFileName) override;
        void supplyIntUniform(const std::string& uniformName,const std::vector<int>& vals) override;
        void Bind() override;
        ~ShaderOpenGL();
    
    private:
        unsigned int mShader{0};

        std::string FileRead(const std::string& fileName);
};

}

#endif