#include <compiled.h>
#include "Prophecy/Core/Window.h"

#ifdef _WINDOWS

#include "Platform/Windows/WindowsWindow.h"

#endif

namespace Prophecy {
    Scope<Window> Window::Create(const WindowProps &props) {

#ifdef _WINDOWS
        return CreateScope<WindowsWindow>(props);
#elsedef __WIN32__
        HZ_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif

    }
}
