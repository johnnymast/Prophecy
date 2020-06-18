//#include "compiled.h"


#include "Prophecy/Core/Application.h"
#include "Base.h"


//#include <GLFW/glfw3.h>

namespace Prophecy {

	Application::Application() {
        m_Window = Window::Create(WindowProps("Hello World"));
	}

	Application::~Application() {

	}

	void Application::Run()
	{
		while (true);
	}

}