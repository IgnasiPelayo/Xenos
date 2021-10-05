#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Xenos
{
	class XENOS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// CORE log macros
#define XE_CORE_TRACE(...)		::Xenos::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define XE_CORE_INFO(...)		::Xenos::Log::GetCoreLogger()->info(__VA_ARGS__)
#define XE_CORE_WARN(...)		::Xenos::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define XE_CORE_ERROR(...)		::Xenos::Log::GetCoreLogger()->error(__VA_ARGS__)
#define XE_CORE_FATAL(...)		::Xenos::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// CLIENT log macros
#define XE_TRACE(...)			::Xenos::Log::GetClientLogger()->trace(__VA_ARGS__)
#define XE_INFO(...)			::Xenos::Log::GetClientLogger()->info(__VA_ARGS__)
#define XE_WARN(...)			::Xenos::Log::GetClientLogger()->warn(__VA_ARGS__)
#define XE_ERROR(...)			::Xenos::Log::GetClientLogger()->error(__VA_ARGS__)
#define XE_FATAL(...)			::Xenos::Log::GetClientLogger()->fatal(__VA_ARGS__)
