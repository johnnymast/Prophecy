#include <compiled.h>
#include "Prophecy/Core/Window.h"

#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64)
#include "Platform/Windows/WindowsWindow.h"
#elif defined(__linux__)
#include "Platform/Linux/LinuxWindow.h"
#endif

namespace Prophecy {
    Scope<Window> Window::Create(const WindowProps &props) {

#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64)
        return CreateScope<WindowsWindow>(props);
#elif defined(__linux__)
        return CreateScope<LinuxWindow>(props);
//#error "Platfom is not supported"
//        HZ_CORE_ASSERT(false, "Unknown platform!");

#else
        return nullptr;
#endif

    }
}
