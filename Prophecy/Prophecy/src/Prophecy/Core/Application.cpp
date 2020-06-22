#include <compiled.h>

#include <Prophecy.h>
#include <Prophecy/Core/LayerStack.h>
#include <typeindex>

namespace Prophecy {

    template<typename T>
    void f(T s)
    {
        const std::type_info& ti1 = typeid(s);

        std::cout << std::type_index(ti1).name() << '\n';
    }
    template void f(int);
    template void f(Vector3d);

    class Test {
    public:
        template<typename T>
        void f(T s);
    };

    template<typename T>
    void Test::f(T s)
    {
        const std::type_info& ti1 = typeid(s);

        std::cout << std::type_index(ti1).name() << '\n';
    }
    template void Test::f(int);
    template void Test::f(Vector3d);

	Application::Application() {
        m_Window = Window::Create(WindowProps("Hello World"));
        LayerStack* stack = LayerStack::Get();
        stack->addLayer(new Layer("Google"));



	}

	Application::~Application() {

	}

	void Application::Run()
	{
        int n;
        std::cin >> n;
//		while (true);
	}

}