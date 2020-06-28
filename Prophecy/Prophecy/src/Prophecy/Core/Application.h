#pragma once

#include "Base.h"
//#include "Prophecy.h"
#include "Prophecy/Core/Window.h"
#include "Prophecy/Event/Event.h"

namespace Prophecy {



    class Application {
    public:
        Application();

        virtual ~Application();


        Window &GetWindow() { return *m_Window; };

        void OnEvent(Event& e);
        void Run();

    protected:
        void Stop();
        void Start();


        void SetAutostart(bool value);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);


        static Application* s_Instance;
        std::unique_ptr<Window> m_Window;
        bool m_Running = false;
        bool m_Autostart = true;
        int m_MaxFps = 60;
        int m_Interval = 1000 / m_MaxFps;
        int m_LastTick = 0;
        int m_Tickes = 0;
        int m_Elapsed = 0;
        int m_FPS = 0;
    };

    Application* CreateApplication();
}

