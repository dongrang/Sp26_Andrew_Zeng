#include "window.hpp"
#include "OpenGLWindow.hpp"
namespace Cervantes {

/**
    Constructor for window,
    add implementation for choosing different graphics api here
    if the need ever arises. Either with enum class or some kind of macro.
*/ 
Window::Window()
{
    m_window = std::make_unique<OpenGLWindow>();
}

void Window::init()
{
    // nb: make_unique is more memory safe than unique_ptr 
    // because the constructor is private, can't use make_unique
    if(m_instance == nullptr)
    {
        m_instance = std::unique_ptr<Window>{new Window};
    }

}

std::unique_ptr<Window>& Window::get()
{
    return m_instance;
}

void Window::create(const Dimensions& dimensions, const std::string& title)
{
    m_window->create(dimensions, title);
}

Dimensions Window::getSize() const
{
    return m_window->getSize();
}

void Window::pollEvents() 
{
    m_window->pollEvents();
}

void Window::swapBuffers()
{
    m_window->swapBuffers();
}
void Window::setWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback)
{
    m_window->setWindowCloseCallback(newCallback);
}
void Window::setKeyCallback(std::function<void(const KeyEvent&)> newCallback)
{
    m_window->setKeyCallback(newCallback);
}


} // end namespace Cervantes
