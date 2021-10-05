#pragma once

#ifdef XE_PLATFORM_WINDOWS

extern Xenos::Application* Xenos::CreateApplication();

int main(int argc, char** argv)
{
	Xenos::Log::Init();
	XE_CORE_WARN("Initialized Log!");
	int a = 5;
	XE_INFO("Hello! Var={0}", a);

	auto app = Xenos::CreateApplication();
	app->Run();
	delete app;
}

#endif
