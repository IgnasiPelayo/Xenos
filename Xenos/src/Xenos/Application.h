#pragma once
#include "Core.h"

namespace Xenos 
{
	class XENOS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}


