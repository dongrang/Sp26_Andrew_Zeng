#include "Cervantes/core/Shader.hpp"
#include "ShaderOpenGL.hpp"
namespace Cervantes {

    Shader::Shader()
    {
        m_shader = std::make_unique<ShaderOpenGL>();
    }
    Shader::Shader(const std::string& vertFileName, const std::string& fragFileName)
    {
        m_shader = std::make_unique<ShaderOpenGL>(vertFileName, fragFileName);
    }

    Shader::Shader(Shader&& other): m_shader(std::move(other.m_shader)) 
    {
    }

    Shader& Shader::operator=(Shader&& other)
    {
        m_shader = std::move(other.m_shader);
        return *this;
    }
    void Shader::loadShader(const std::string& vertFileName, const std::string& fragFileName)
    {
        m_shader->loadShader(vertFileName, fragFileName);
    }

    void Shader::supplyIntUniform(const std::string& uniformName,const std::vector<int>& vals)
    {
        m_shader->supplyIntUniform(uniformName,vals);
    }

    void Shader::Bind()
    {
        m_shader->Bind();
    }
} // end namespace Cervantes