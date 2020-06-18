#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "Base.h"

namespace Prophecy {
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define PROPHECY_CORE_TRACE(...)    ::Prophecy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PROPHECY_CORE_INFO(...)     ::Prophecy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PROPHECY_CORE_WARN(...)     ::Prophecy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PROPHECY_CORE_ERROR(...)    ::Prophecy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PROPHECY_CORE_CRITICAL(...) ::Prophecy::Log::GetCoreLogger()->critical(__VA_ARGS__)
									  
// Client log macros			  
#define PROPHECY_TRACE(...)         ::Prophecy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PROPHECY_INFO(...)          ::Prophecy::Log::GetClientLogger()->info(__VA_ARGS__)
#define PROPHECY_WARN(...)          ::Prophecy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PROPHECY_ERROR(...)         ::Prophecy::Log::GetClientLogger()->error(__VA_ARGS__)
#define PROPHECY_CRITICAL(...)      ::Prophecy::Log::GetClientLogger()->critical(__VA_ARGS__)