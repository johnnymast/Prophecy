#pragma once
#include "Base.h"
#include "Prophecy/Core//Window.h"

namespace Prophecy {
    class Application {
    public:
        Application();

        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
    };

    Application *CreateApplication();
}

