#include <compiled.h>
#include "Prophecy/Core/Window.h"

#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64)
    #include "Platform/Windows/Core/WindowsWindow.h"
#elif defined(__linux__)
    #include "Platform/Linux/Core/MacOSWindow.h"
#elif defined(__APPLE__)
    #include "Platform/MacOS/Core/MacOSWindow.h"
#endif

namespace Prophecy {
    Scope<Window> Window::Create(const WindowProps &props) {

#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64)
        return CreateScope<WindowsWindow>(props);
#elif defined(__linux__)
        return CreateScope<LinuxWindow>(props);
#elif defined(__APPLE__)
        return CreateScope<MacOSWindow>(props);
#else
        return nullptr;
#endif

    }
}
