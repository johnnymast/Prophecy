#pragma once
#include "Base.h"

namespace Prophecy {
    class Application {
    public:
        Application();

        virtual ~Application();

        void Run();
    };

    Application *CreateApplication();
}

