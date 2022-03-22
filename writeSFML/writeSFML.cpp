 #pragma once
#include "TextBox.hpp"
#include "Group.hpp"
#include "Typedef.hpp"
#include "Scene.hpp"
#include <cassert>
#include <thread>
#include <SFML/Audio.hpp>
#include <random>

using namespace sf;

void main_rend(Event& ev);

int main()
{
	sf::Event event;
	main_rend(event);

    return 0;
}


void main_rend(Event& ev) 
{
	sf::Font font;
	font.loadFromFile("fonts/19809.otf");
	auto label = std::make_shared<InterfaceComp::TextBox>(font, 100, 100, L"String");
	auto label2 = std::make_shared<InterfaceComp::TextBox>(font, 100, 100, L"String2");
	auto label3 = std::make_shared<InterfaceComp::TextBox>(font, 100, 100, L"String3");

	auto group = std::make_shared<InterfaceComp::Group>(std::initializer_list<InterfaceComp::BaseInerface*>{label.get(), label2.get(), label3.get()});

	group->setPosition(100, 100);

	auto scene = std::make_shared<Rep::Scene>();

	scene->editRep().insert(group.get());

	while (scene->getWindow()->isOpen()) {

		while (scene->getWindow()->pollEvent(ev)) {
			if (ev.type == Event::Closed) {
				scene->getWindow()->close();
			}

			if (ev.type == ev.MouseButtonPressed && ev.mouseButton.button == Mouse::Left)
			{

			}
		}

		scene->update();
		scene->build();
	}
}