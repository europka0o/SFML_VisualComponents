#include "TextBox.hpp"

//-----------------------------------Текст-TextBox-Начало-------------------------------------
InterfaceComp::TextBox::TextBox(const Font& font, int x, int y, const wchar_t* txt, const Color& lbcol, const Color& bvcol) :
	BaseInerface(x, y, FloatRect(Vector2f(0, 0), Vector2f(0, 0))),
	visible_bevel(true)
{
	label = new Text;
	label->setFont(font);
	label->setString(txt);
	label->setCharacterSize(InterfaceComp::text_size::small_t);

	label->setFillColor(lbcol);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));

	bevel = new RectangleShape;
	bevel->setSize(Vector2f(label->getGlobalBounds().width + 10, label->getGlobalBounds().height + 10));
	bevel->setFillColor(bvcol);
	bevel->setPosition(pos.x, pos.y);

	setSize(bevel->getGlobalBounds());

}

InterfaceComp::TextBox::~TextBox() {
	delete label, bevel;
}

void InterfaceComp::TextBox::setString(const wchar_t* txt) {
	label->setString(txt);
	InterfaceComp::TextBox::resize(label->getCharacterSize());
}

void InterfaceComp::TextBox::setFont(const Font& font) {
	label->setFont(font);
}

void InterfaceComp::TextBox::setPosition(const axes_i& xy) {
	pos = xy;
	bevel->setPosition(pos.x, pos.y);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));

	fl_rect = bevel->getGlobalBounds();
}

void __fastcall InterfaceComp::TextBox::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;
	bevel->setPosition(pos.x, pos.y);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));

	fl_rect = bevel->getGlobalBounds();
}

void InterfaceComp::TextBox::resize(int size) {
	label->setCharacterSize(size);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));
	bevel->setSize(Vector2f(label->getGlobalBounds().width + 10, label->getGlobalBounds().height + 10));

	fl_rect = bevel->getGlobalBounds();
}

void InterfaceComp::TextBox::renderChild(const RenderWindowPtr& window) {
	if (visible) {
		if (visible_bevel) {
			window->draw(*bevel);
		}
		window->draw(*label);
	}
}
//-----------------------------------Текст-TextBox-Конец-------------------------------------