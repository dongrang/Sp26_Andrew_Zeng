#include "OpenGLWindow.hpp"

namespace Cervantes {

/**
    Private
*/

void OpenGLWindow::framebufferSizeCallback(GLFWwindow* window,int width, int height)
{
    glViewport(0,0,width,height);
}

/**
    Public
*/
OpenGLWindow::~OpenGLWindow()
{
    if(m_windowPtr != nullptr)
    {
        glfwDestroyWindow(m_windowPtr);
    }
    glfwTerminate();
}

void OpenGLWindow::create(const Dimensions& dimensions, const std::string& title)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHintString(GLFW_WAYLAND_APP_ID, "CustomAppClass");

    m_windowPtr = glfwCreateWindow(static_cast<int>(dimensions.width), static_cast<int>(dimensions.height), title.c_str(), nullptr, nullptr);

    if(m_windowPtr == nullptr)
    {
        std::cout << "Failed to create GLFW window.\n";
        glfwTerminate();
        return;
    }
        //make context(drawing context) means "if you draw something, draw it here at this window", the window controlled by this pointer
    glfwMakeContextCurrent(m_windowPtr);

    glfwSetFramebufferSizeCallback(m_windowPtr, framebufferSizeCallback);

    if(!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Couldn't open OpenGL.\n";
        glfwTerminate();
        return;
    }

    glViewport(0,0,static_cast<int>(dimensions.width),static_cast<int>(dimensions.height));

    glfwSetWindowUserPointer(m_windowPtr, &mCallBacks);

    glfwSetKeyCallback(m_windowPtr, [](GLFWwindow* winPtr,int key,int scancode,int action,int mods){

        KeyEvent event{(Key)key,KeyEvent::KeyAction::UNDEFINED};

        switch(action)
        {
            case GLFW_PRESS: 
                event.setAction(KeyEvent::KeyAction::PRESS);
                break;
            case GLFW_REPEAT:
                event.setAction(KeyEvent::KeyAction::REPEAT);
                break;                
            case GLFW_RELEASE:
                event.setAction(KeyEvent::KeyAction::RELEASE);
                break;
        }

        Callbacks* userPtr{ (Callbacks*)glfwGetWindowUserPointer(winPtr) };

        userPtr->KeyCallback(event);
            });

        glfwSetWindowCloseCallback(m_windowPtr, [](GLFWwindow* winPtr){
            WindowCloseEvent event;
            Callbacks* userPtr{ (Callbacks*)glfwGetWindowUserPointer(winPtr) };

            userPtr->WindowCloseCallback(event);
            });
}

Dimensions OpenGLWindow::getSize() const 
{
    int width{0},height{0};
    glfwGetWindowSize(m_windowPtr, &width, &height);
    return {static_cast<std::uint32_t>(width),static_cast<std::uint32_t>(height)};
}

void OpenGLWindow::pollEvents()
{
    glfwPollEvents();
}

void OpenGLWindow::swapBuffers()
{
    glfwSwapBuffers(m_windowPtr);
}
void OpenGLWindow::setWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback) 
{
    mCallBacks.WindowCloseCallback = newCallback;
}
void OpenGLWindow::setKeyCallback(std::function<void(const KeyEvent&)> newCallback)
{
    mCallBacks.KeyCallback = newCallback;
}


} // end namespace Cervantes