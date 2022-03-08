#pragma once
#include "TextBox.hpp"
#include "Typedef.hpp"
#include <cassert>
#include <thread>
#include <SFML/Audio.hpp>
#include <random>

using namespace sf;

void main_rend(Event& ev, const RenderWindowPtr& window);

int main()
{
	sf::Event event;
	auto window = std::make_shared<sf::RenderWindow>(VideoMode(1920, 1080), "TextBox", Style::Default);

	main_rend(event, window);

    return 0;
}


void main_rend(Event& ev, const RenderWindowPtr& window) {

	Vector2i mouse_pos = Mouse::getPosition(*window);
	mouse_pos = Vector2i(window->mapPixelToCoords(mouse_pos));

	sf::Font font;
	font.loadFromFile("fonts/19809.otf");
	auto label = std::make_shared<InterfaceComp::TextBox>(font, 100, 100, L"String");
	label->resize(40);
	DrawManager draw;

	draw.add(label.get());

	while (window->isOpen()) {

		while (window->pollEvent(ev)) {
			if (ev.type == Event::Closed) {
				window->close();
			}

			mouse_pos = Mouse::getPosition(*window);
			mouse_pos = Vector2i(window->mapPixelToCoords(mouse_pos));

			if (ev.type == ev.MouseButtonPressed && ev.mouseButton.button == Mouse::Left)
			{

			}
		}

		window->clear();
		draw.render(window);
		window->display();
	}
}