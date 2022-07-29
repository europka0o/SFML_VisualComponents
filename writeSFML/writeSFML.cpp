 #pragma once
#include "Application.hpp"

int main()
{
	auto app = std::make_shared<Platform::Application>();

	if (app->Start())
	{
		app->Exec();
	}

	app->Exit();

    return 0;
}