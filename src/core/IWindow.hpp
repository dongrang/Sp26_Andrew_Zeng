#ifndef IWINDOW_HPP
#define IWINDOW_HPP

#include "Cervantes/core/types.hpp"
#include "Cervantes/core/Events.hpp"
namespace Cervantes {

class IWindow {
    public:
        virtual ~IWindow() = default;
        virtual void create(const Dimensions& dimensions, const std::string& title) = 0;
        virtual Dimensions getSize() const = 0;

        virtual void pollEvents() = 0;
        virtual void swapBuffers() = 0;

        virtual void setWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback) = 0;
        virtual void setKeyCallback(std::function<void(const KeyEvent&)> newCallback) = 0;

};

} // end namespace Cervantes

#endif