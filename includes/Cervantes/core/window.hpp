#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "../../../src/core/IWindow.hpp"

namespace Cervantes {

class Window 
{
    public:

        static void init();
        static std::unique_ptr<Window>& get();

        void create(const Dimensions& dimensions, const std::string& title);
        Dimensions getSize() const;

        void pollEvents();
        void swapBuffers();

        void setWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback);
        void setKeyCallback(std::function<void(const KeyEvent&)> newCallback);

    private:
        Window();
        inline static std::unique_ptr<Window> m_instance{nullptr};
        std::unique_ptr<IWindow> m_window{nullptr};

};

} // end namespace Cervantes


#endif