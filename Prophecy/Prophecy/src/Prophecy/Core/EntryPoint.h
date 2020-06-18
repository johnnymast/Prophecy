#pragma once

//#include <Prophecy>
#include "Prophecy/Core/Base.h"

//#ifdef PR_PLATFORM_WINDOWS

extern Prophecy::Application* Prophecy::CreateApplication();

int main(int argc, char** argv)
{
	Prophecy::Log::Init();

	PROPHECY_CORE_INFO("Logs initialized.");
	PROPHECY_CORE_INFO("Calling client to create application.");

	auto app = Prophecy::CreateApplication();

	PROPHECY_CORE_INFO("Application created.");

	app->Run();
	delete app;
}


//#endif