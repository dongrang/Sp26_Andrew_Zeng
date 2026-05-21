#ifndef OPENGL_WINDOW_HPP
#define OPENGL_WINDOW_HPP

#include "IWindow.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace Cervantes {

class OpenGLWindow : public IWindow {
    public:
        ~OpenGLWindow() override;     
        void create(const Dimensions& dimensions, const std::string& title) override;
        Dimensions getSize() const override;

        void pollEvents() override;
        void swapBuffers() override;
        
        void setWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback) override;
        void setKeyCallback(std::function<void(const KeyEvent&)> newCallback) override;

    private:
        GLFWwindow* m_windowPtr{nullptr};
        static void framebufferSizeCallback(GLFWwindow* window,int width, int height);
        
        struct Callbacks {
            std::function<void(const WindowCloseEvent&)> WindowCloseCallback;        
            std::function<void(const KeyEvent&)> KeyCallback;         
        } mCallBacks;


};


}// end namespace Cervantes

#endif