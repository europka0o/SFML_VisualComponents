#include "Application.hpp"
#include "TextBox.hpp"
#include "Group.hpp"
#include "Typedef.hpp"
#include "Scene.hpp"
#include <cassert>
#include <thread>
#include <SFML/Audio.hpp>
#include <random>

using namespace sf;

namespace Platform 
{
	bool Application::Start() 
	{
		return true;
	}

	bool Application::Exit() 
	{
		return true;
	}

	void Application::Exec() 
	{
		auto run = [this]()
		{
			sf::Font font;
			font.loadFromFile("fonts/19809.otf");
			auto label = std::make_shared<InterfaceComp::TextBox>(font, 100, 100, L"String1");
			label->resize(120);
			auto label2 = std::make_shared<InterfaceComp::TextBox>(font, 100, 100, L"String2");
			auto label3 = std::make_shared<InterfaceComp::TextBox>(font, 100, 100, L"String3");
			
			auto group = std::make_shared<InterfaceComp::Group>(std::initializer_list<InterfaceComp::BaseInerface*>{label.get(), label2.get(), label3.get()});
			group->setPosition(100, 100);

			auto scene = std::make_shared<Rep::Scene>();

			scene->editRep().insert(group.get());

			while (scene->getWindow()->isOpen()) {

				while (scene->getWindow()->pollEvent(appEvent)) {
					if (appEvent.type == Event::Closed) {
						scene->getWindow()->close();
					}

					if (appEvent.type == appEvent.MouseButtonPressed && appEvent.mouseButton.button == Mouse::Left)
					{

					}
				}

				scene->update();
				scene->build();
			}
		};

		auto main = std::thread{ run };
		main.join();
	}
}