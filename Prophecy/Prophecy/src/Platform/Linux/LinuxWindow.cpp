#include <compiled.h>
#include "Platform/Linux/LinuxWindow.h"
#include <GLFW/glfw3.h>

namespace Prophecy {
    static uint8_t s_GLFWWindowCount = 0;

    LinuxWindow::LinuxWindow(const WindowProps& props)
    {
    //    HZ_PROFILE_FUNCTION();

        Init(props);
    }

    LinuxWindow::~LinuxWindow()
    {
     //   HZ_PROFILE_FUNCTION();

        Shutdown();
    }

    void LinuxWindow::Init(const WindowProps& props)
    {
        //HZ_PROFILE_FUNCTION();

        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        PROPHECY_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (s_GLFWWindowCount == 0)
        {
//            HZ_PROFILE_SCOPE("glfwInit");
            int success = glfwInit();
//            HZ_CORE_ASSERT(success, "Could not initialize GLFW!");
//            glfwSetErrorCallback(GLFWErrorCallback);
        }

        {
//            HZ_PROFILE_SCOPE("glfwCreateWindow");
#if defined(HZ_DEBUG)
            if (Renderer::GetAPI() == RendererAPI::API::OpenGL)
				glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
            m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
            ++s_GLFWWindowCount;
        }

//        m_Context = GraphicsContext::Create(m_Window);
//        m_Context->Init();

//        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
//
//        // Set GLFW callbacks
//        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//            data.Width = width;
//            data.Height = height;
//
//            WindowResizeEvent event(width, height);
//            data.EventCallback(event);
//        });
//
//        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//            WindowCloseEvent event;
//            data.EventCallback(event);
//        });
//
//        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            switch (action)
//            {
//                case GLFW_PRESS:
//                {
//                    KeyPressedEvent event(static_cast<KeyCode>(key), 0);
//                    data.EventCallback(event);
//                    break;
//                }
//                case GLFW_RELEASE:
//                {
//                    KeyReleasedEvent event(static_cast<KeyCode>(key));
//                    data.EventCallback(event);
//                    break;
//                }
//                case GLFW_REPEAT:
//                {
//                    KeyPressedEvent event(static_cast<KeyCode>(key), 1);
//                    data.EventCallback(event);
//                    break;
//                }
//            }
//        });
//
//        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            KeyTypedEvent event(static_cast<KeyCode>(keycode));
//            data.EventCallback(event);
//        });
//
//        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            switch (action)
//            {
//                case GLFW_PRESS:
//                {
//                    MouseButtonPressedEvent event(static_cast<MouseCode>(button));
//                    data.EventCallback(event);
//                    break;
//                }
//                case GLFW_RELEASE:
//                {
//                    MouseButtonReleasedEvent event(static_cast<MouseCode>(button));
//                    data.EventCallback(event);
//                    break;
//                }
//            }
//        });
//
//        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            MouseScrolledEvent event((float)xOffset, (float)yOffset);
//            data.EventCallback(event);
//        });
//
//        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
//        {
//            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
//            MouseMovedEvent event((float)xPos, (float)yPos);
//            data.EventCallback(event);
//        });
    }


    void LinuxWindow::Shutdown()
    {
//        HZ_PROFILE_FUNCTION();

        glfwDestroyWindow(m_Window);
        --s_GLFWWindowCount;

        if (s_GLFWWindowCount == 0)
        {
            glfwTerminate();
        }
    }


    void LinuxWindow::OnUpdate()
    {
//        HZ_PROFILE_FUNCTION();

        glfwPollEvents();
//        m_Context->SwapBuffers();
    }

    void LinuxWindow::SetVSync(bool enabled)
    {
//        HZ_PROFILE_FUNCTION();

        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool LinuxWindow::IsVSync() const
    {
        return m_Data.VSync;
    }



}