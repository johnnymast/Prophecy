#include <iostream>

#include <Prophecy.h>
#include <Prophecy/Core/EntryPoint.h>

class Sandbox : public Prophecy::Application {
public:
    Sandbox() {
      //  PROPHECY_INFO("Client operational.");
    }

    ~Sandbox() {
        //
    }
};

Prophecy::Application* Prophecy::CreateApplication() {
	return new Sandbox();
}