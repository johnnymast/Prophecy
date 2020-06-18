#include <compiled.h>
#include "Prophecy/Core/Window.h"

#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64)

#include "Platform/Windows/WindowsWindow.h"

#endif

namespace Prophecy {
    Scope<Window> Window::Create(const WindowProps &props) {

#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64)
        return CreateScope<WindowsWindow>(props);
#else if defined(__WIN32__)
        HZ_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif

    }
}
