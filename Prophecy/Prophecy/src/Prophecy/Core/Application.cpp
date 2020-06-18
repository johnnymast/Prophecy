#include <compiled.h>

#include <Prophecy.h>
#include <Prophecy/Core/LayerStack.h>

namespace Prophecy {

	Application::Application() {
        //m_Window = Window::Create(WindowProps("Hello World"));
        LayerStack* stack = LayerStack::Get();
        stack->addLayer(new Layer("Google"));

	}

	Application::~Application() {

	}

	void Application::Run()
	{
		while (true);
	}

}