#pragma once

#ifdef XE_PLATFORM_WINDOWS

extern Xenos::Application* Xenos::CreateApplication();

int main(int argc, char** argv)
{
	printf("Xenos Engine");
	auto app = Xenos::CreateApplication();
	app->Run();
	delete app;
}

#endif
