#include <compiled.h>
#include <chrono>

#include <Prophecy.h>
#include <Prophecy/Core/LayerStack.h>
#include <typeindex>
#include "Application.h"
#include <GLFW/glfw3.h>

namespace Prophecy {


    Application *Application::s_Instance = nullptr;


    Application::Application() {
        m_Window = Window::Create(WindowProps("Prophecy Engine"));
        s_Instance = this;

        m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));

//        LayerStack* stack = LayerStack::Get();
//        stack->addLayer(new Layer("Google"));

    }

    Application::~Application() {

    }

    void Application::Run() {
        if (m_Autostart && !m_Running) {
            PROPHECY_CORE_INFO("Autostart: enabled");
            Start();
        } else {
            PROPHECY_CORE_INFO("Autostart: disabled.");
        }

        std::cout << "Rum " << std::endl;

        while (m_Running) {

            auto now = clock();
            auto delta = now - m_LastTick;

           // while (delta >= m_Interval) {
                m_Tickes++;
                m_Elapsed = now - m_LastTick;
                m_LastTick = now - (delta % m_Interval);
              //  m_FPS = 1000 / m_Elapsed;
                m_Window->OnUpdate();
        //    }
        }
    }

    void Application::SetAutostart(bool value) {
        m_Autostart = value;
    }

    void Application::Start() {
        m_Running = true;
    }


    void Application::Stop() {
        m_Running = false;
    }

    void Application::OnEvent(Event &e) {
//        HZ_PROFILE_FUNCTION();

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClose));
            dispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(Application::OnWindowResize));

//        for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
//        {
//            if (e.Handled)
//                break;
//            (*it)->OnEvent(e);
//        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e) {
        std::cout << "OnWindowClose" << std::endl;
        m_Running = false;
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e) {
        m_Running = false;
        return true;
    }


}