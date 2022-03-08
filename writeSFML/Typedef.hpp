#pragma once
#include <SFML/Graphics.hpp>

using RenderWindowPtr = std::shared_ptr<sf::RenderWindow>;

namespace InterfaceComp
{
	class TextBox;
	using TextBoxPtr = std::shared_ptr<TextBox>;
}