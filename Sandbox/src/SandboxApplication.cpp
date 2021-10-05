#include <Xenos.h>


class Sandbox : public Xenos::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Xenos::Application* Xenos::CreateApplication()
{
	return new Sandbox();
}