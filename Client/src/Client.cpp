#include <iostream>

#include <Prophecy.h>
#include <Prophecy/Core/EntryPoint.h>
#include <signal.h>

class Sandbox : public Prophecy::Application {
public:
    Sandbox() {
        PROPHECY_INFO("Client operational.");
        SetAutostart(false);
     //   Run();
     //   Start();

//        __debugbreak();
//        raise(5);
    }

    ~Sandbox() {
        //
    }
};

Prophecy::Application* Prophecy::CreateApplication() {
	return new Sandbox();
}