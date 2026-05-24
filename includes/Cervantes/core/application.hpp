#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Events.hpp"

constexpr int FRAMES_PER_SECOND{ 60 };

namespace Cervantes {

class Application {

    public: 

        Application();

        virtual void update();
        virtual void init();
        virtual void shutdown();

        void run();

        void setWindowCloseCallback(std::function<void(const WindowCloseEvent&)>);
        void setKeyCallback(std::function<void(const KeyEvent&)>);

        virtual ~Application() = default;

    protected:

        bool keys_array_[1024] = {false};
        
    private: 

        std::chrono::milliseconds m_frameduration{ 1000 / FRAMES_PER_SECOND };
        std::chrono::steady_clock::time_point m_nextframetime;

        bool mShouldContinue{ true };
        void defaultWindowCloseCallback(const WindowCloseEvent&);

        
    };

} // end namespace Cervantes
#endif