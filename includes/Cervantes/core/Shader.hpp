#ifndef SHADER_HPP
#define SHADER_HPP

#include "../../../src/core/IShader.hpp"
namespace Cervantes {

class Shader {
    public:
        Shader();
        Shader(const std::string& vertFileName, const std::string& fragFileName);
        void loadShader(const std::string& vertFileName, const std::string& fragFileName);
        void supplyIntUniform(const std::string& uniformName,const std::vector<int>& vals);

        Shader(const Shader&) = delete;
        Shader& operator=(const Shader&) = delete;
        Shader(Shader&& other);
        Shader& operator=(Shader&& other);
         
    private:
        std::unique_ptr<IShader> m_shader{nullptr};
        void Bind();

        friend class OpenGLRenderer;
};      

} // end namespace Cervantes

#endif