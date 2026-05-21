#include "Cervantes/core/application.hpp"
#include "Cervantes/core/Unit.hpp"
#include "Cervantes/core/Renderer.hpp"

#include "window.hpp"
#include <stb_image.h>
#include <glad/gl.h>

namespace Cervantes {

    Application::Application()
    {
        Window::init();
        Window::get()->create({1000,1000}, "Current Window.");

        /*
            passes lambda function to the game engine
            lambda calls defaultWindowCloseCallback
        */
        setWindowCloseCallback([this](const WindowCloseEvent& event) {defaultWindowCloseCallback(event); });

        Renderer::init();
    }

    void Application::update()
    {

    }

    void Application::init()
    {

    }

    void Application::shutdown()
    {

    }
    void Application::run()
    {
        init();

        m_nextframetime = std::chrono::steady_clock::now() + m_frameduration;
            
        while(mShouldContinue)
        {
            Renderer::get()->screenClear();
            update();

            std::this_thread::sleep_until(m_nextframetime);
            m_nextframetime = std::chrono::steady_clock::now() + m_frameduration;

            Window::get()->swapBuffers();
            Window::get()->pollEvents();
        }
        shutdown();
    }

    void Application::setWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback)
    {
        Window::get()->setWindowCloseCallback(newCallback);
    }

    void Application::setKeyCallback(std::function<void(const KeyEvent&)> newCallback)
    {
        Window::get()->setKeyCallback(newCallback);
    }

    void Application::defaultWindowCloseCallback(const WindowCloseEvent&)
    {
        mShouldContinue = false;
    }
} // end namespace Cervantes