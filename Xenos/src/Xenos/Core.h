#pragma once

#ifdef XE_PLATFORM_WINDOWS
	#ifdef XE_BUILD_DLL
		#define XENOS_API __declspec(dllexport)
	#else
		#define XENOS_API __declspec(dllimport)
	#endif
#else
	#error Xenos only support Windows!
#endif