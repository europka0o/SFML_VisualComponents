/*#include "Interf_comp.h"


int getInputMethod() { //1033 - EN, 1049 - RU
	HWND hwnd = GetForegroundWindow();
	if (hwnd) {
		DWORD threadID = GetWindowThreadProcessId(hwnd, NULL);
		HKL currentLayout = GetKeyboardLayout(threadID);
		unsigned int x = (unsigned int)currentLayout & 0x0000FFFF;
		return ((int)x);
	}
	return 0;
}

unsigned __int64 wstrToInt(std::wstring input) { //Парсер строки к целочисленному беззначному
	unsigned __int64 output;
	std::wistringstream ist(input);
	ist >> output;
	return output;
}

//----------------------------------Структура-оси-axes-Начало-------------------------------
template<typename type>
axes<type>::axes() {
	x = 0;
	y = 0;
}

template<typename type>
axes<type>::axes(type _x, type _y) : x(_x), y(_y) {}
//----------------------------------Структура-оси-axes-Конец-------------------------------

//-------------------------------------------------------------------------------------------------------------
template<typename arg>
arg _repoz_x(arg X, arg size, arg indent) {
	arg A = 0;
	A = size - X;
	X = X - A;
	return X + indent;
}

template<typename arg>
arg _repoz_y(arg Y, arg size, arg indent) {
	arg A = 0;
	A = size - Y;
	Y = Y - A;
	return Y + indent;
}
//-------------------------------------------------------------------------------------------------------------

//--------------------------------База-Интерфейса-BaseInterface-Начало------------------------------------------
BaseInerface::BaseInerface() :
	pos(axes_i(0, 0)),
	visible(true) {
}

BaseInerface::BaseInerface(int x, int y, const FloatRect& rect) :
	pos(axes_i(x, y)),
	fl_rect(rect),
	visible(true) {
}

BaseInerface::BaseInerface(const axes_i& xy, const FloatRect& rect) :
	pos(xy),
	fl_rect(rect),
	visible(true) {
}

BaseInerface::~BaseInerface() {
}

axes_i BaseInerface::getPosition() {
	return pos;
}

void BaseInerface::setPosition(const axes_i& xy) {
	pos = xy;
}

void BaseInerface::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;
}

FloatRect BaseInerface::getSize() {
	return fl_rect;
}

void BaseInerface::render(RenderWindow& wd) {

}
void BaseInerface::render(RenderWindow* wd) {

}
//--------------------------------База-Интерфейса-BaseInterface-Конец------------------------------------------

//-----------------------------------Текст-text-Начало-------------------------------------
text::text(int x = 0, int y = 0, std::wstring txt = L"ERR:", Color lbcol = Color::White, Color bvcol = Color::Black) :
	BaseInerface(x, y, FloatRect(Vector2f(0, 0), Vector2f(0, 0))),
	visible_bevel(true),
	shift(false)
{
	#undef small
	font_main = new Font;
	font_main->loadFromFile("fonts/quivira.regular.otf");
	label = new Text;
	label->setFont(*font_main);
	label->setString(txt);
	label->setCharacterSize(text_size::small);

	label->setFillColor(lbcol);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));

	bevel = new RectangleShape;
	bevel->setSize(Vector2f(label->getGlobalBounds().width + 10, label->getGlobalBounds().height + 10));
	bevel->setFillColor(bvcol);
	bevel->setPosition(pos.x, pos.y);
	
	fl_rect = bevel->getGlobalBounds();
	#define small char
}

text::~text() {
	delete font_main, label, bevel;
}

std::wstring text::exec_console(const std::wstring &command) {
	int iter = 0;
	std::wstring buff;
	if (command.find(L"TEXT.SETPOSITION") != std::wstring::npos) {
		int x, y;
		iter = command.find(L"[") + 1;
		
		while (command[iter] != L',') {
			buff += command[iter];
			iter++;
		}
		x = wstrToInt(buff);
		buff = L"";
		iter += 1;
		
		while (command[iter] != L']') {
			buff += command[iter];
			iter++;
		}
		y = wstrToInt(buff);

		this->setPosition(x, y);
		return L"Successfully";
	} else if (command.find(L"TEXT.RESIZE") != std::wstring::npos) {
		int size;
		iter = command.find(L"[") + 1;

		while (command[iter] != L']') {
			buff += command[iter];
			iter++;
		}
		size = wstrToInt(buff);

		this->resize(size);
		return L"Successfully";
	}
	return L"Failed";
}

std::wstring text::changeWString(const Event &event) {
	std::wstring buff;
	wchar_t symb;
	buff = label->getString();

	if (getInputMethod() == 1033) {
		switch (event.key.code) {

			case Keyboard::Q: symb = L'Q'; break;
			case Keyboard::W: symb = L'W'; break;
			case Keyboard::E: symb = L'E'; break;
			case Keyboard::R: symb = L'R'; break;
			case Keyboard::T: symb = L'T'; break;
			case Keyboard::Y: symb = L'Y'; break;
			case Keyboard::U: symb = L'U'; break;
			case Keyboard::I: symb = L'I'; break;
			case Keyboard::O: symb = L'O'; break;
			case Keyboard::P: symb = L'P'; break;
			case Keyboard::A: symb = L'A'; break;
			case Keyboard::S: symb = L'S'; break;
			case Keyboard::D: symb = L'D'; break;
			case Keyboard::F: symb = L'F'; break;
			case Keyboard::G: symb = L'G'; break;
			case Keyboard::H: symb = L'H'; break;
			case Keyboard::J: symb = L'J'; break;
			case Keyboard::K: symb = L'K'; break;
			case Keyboard::L: symb = L'L'; break;
			case Keyboard::Z: symb = L'Z'; break;
			case Keyboard::X: symb = L'X'; break;
			case Keyboard::C: symb = L'C'; break;
			case Keyboard::V: symb = L'V'; break;
			case Keyboard::B: symb = L'B'; break;
			case Keyboard::N: symb = L'N'; break;
			case Keyboard::M: symb = L'M'; break;

			case Keyboard::Num0: symb = L'0'; break;
			case Keyboard::Num1: symb = L'1'; break;
			case Keyboard::Num2: symb = L'2'; break;
			case Keyboard::Num3: symb = L'3'; break;
			case Keyboard::Num4: symb = L'4'; break;
			case Keyboard::Num5: symb = L'5'; break;
			case Keyboard::Num6: symb = L'6'; break;
			case Keyboard::Num7: symb = L'7'; break;
			case Keyboard::Num8: symb = L'8'; break;
			case Keyboard::Num9: symb = L'9'; break;

			case Keyboard::LBracket: symb = L'['; break;
			case Keyboard::RBracket: symb = L']'; break;
			case Keyboard::Space: symb = 0x0020; break;
			case Keyboard::Tilde: symb = 0x007E; break;
			case Keyboard::Tab: symb = 0x0009; break;
			case Keyboard::Comma: symb = L','; break;
			case Keyboard::Period: symb = 0x002E; break;
			case Keyboard::Backspace:	buff.pop_back();	
										return buff; break;

			case Keyboard::Enter: std::wcout << text::exec_console(buff) << std::endl; return buff; break;
			default: return buff; break;
		}
	}
	else if (getInputMethod() == 1049) {
		switch (event.key.code) {

			case Keyboard::Q: symb = L'Й'; break;
			case Keyboard::W: symb = L'Ц'; break;
			case Keyboard::E: symb = L'У'; break;
			case Keyboard::R: symb = L'К'; break;
			case Keyboard::T: symb = L'Е'; break;
			case Keyboard::Y: symb = L'Н'; break;
			case Keyboard::U: symb = L'Г'; break;
			case Keyboard::I: symb = L'Ш'; break;
			case Keyboard::O: symb = L'Щ'; break;
			case Keyboard::P: symb = L'З'; break;
			case Keyboard::LBracket: symb = L'Х'; break;
			case Keyboard::RBracket: symb = L'Ъ'; break;
			case Keyboard::A: symb = L'Ф'; break;
			case Keyboard::S: symb = L'Ы'; break;
			case Keyboard::D: symb = L'В'; break;
			case Keyboard::F: symb = L'А'; break;
			case Keyboard::G: symb = L'П'; break;
			case Keyboard::H: symb = L'Р'; break;
			case Keyboard::J: symb = L'О'; break;
			case Keyboard::K: symb = L'Л'; break;
			case Keyboard::L: symb = L'Д'; break;
			case Keyboard::Semicolon: symb = L'Ж'; break;
			case Keyboard::Quote: symb = L'Э'; break;
			case Keyboard::Z: symb = L'Я'; break;
			case Keyboard::X: symb = L'Ч'; break;
			case Keyboard::C: symb = L'С'; break;
			case Keyboard::V: symb = L'М'; break;
			case Keyboard::B: symb = L'И'; break;
			case Keyboard::N: symb = L'Т'; break;
			case Keyboard::M: symb = L'Ь'; break;
			case Keyboard::Comma: symb = L'Б'; break;
			case Keyboard::Period: symb = L'Ю'; break;

			case Keyboard::Num0: symb = L'0'; break;
			case Keyboard::Num1: symb = L'1'; break;
			case Keyboard::Num2: symb = L'2'; break;
			case Keyboard::Num3: symb = L'3'; break;
			case Keyboard::Num4: symb = L'4'; break;
			case Keyboard::Num5: symb = L'5'; break;
			case Keyboard::Num6: symb = L'6'; break;
			case Keyboard::Num7: symb = L'7'; break;
			case Keyboard::Num8: symb = L'8'; break;
			case Keyboard::Num9: symb = L'9'; break;

			case Keyboard::Space: symb = 0x0020; break;
			case Keyboard::Tilde: symb = 0x007E; break;
			case Keyboard::Tab: symb = 0x0009; break;
			case Keyboard::Backspace:	buff.pop_back();
										return buff; break;

			default: return buff; break;
		}
	}
	return buff += symb;
}

void text::addWChar(const Event &event, int mode) {

	if (event.type == mode) {
		label->setString(text::changeWString(event));
		text::resize(label->getCharacterSize());
	}
}

void text::addWChar(wchar_t symb) {
	std::wstring str_out = label->getString();
	str_out += symb;
	this->setString(str_out);
}

void text::addWChar(char32_t symb) {
	sf::String str_out = label->getString();
	str_out += symb;
	this->setString(str_out);
}

bool text::isAction(const Vector2i& pos) {
	bool active;
	bevel->getGlobalBounds().contains(pos.x, pos.y) ? active = true : active = false;
	return active;
}

void text::setString(std::wstring txt) noexcept {
	label->setString(txt);
	text::resize(label->getCharacterSize());
}

void text::setString(sf::String txt) noexcept {
	label->setString(txt);
	text::resize(label->getCharacterSize());
}

void text::setFont(String txt) noexcept {
	font_main->loadFromFile(txt);
}

void text::setPosition(const axes_i& xy) noexcept {
	pos = xy;
	bevel->setPosition(pos.x, pos.y);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));

	fl_rect = bevel->getGlobalBounds();
}

void __fastcall text::setPosition(int x, int y) noexcept {
	pos.x = x;
	pos.y = y;
	bevel->setPosition(pos.x, pos.y);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));

	fl_rect = bevel->getGlobalBounds();
}

void text::resize(int size = normal) noexcept {
	label->setCharacterSize(size);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));
	bevel->setSize(Vector2f(label->getGlobalBounds().width + 10, label->getGlobalBounds().height + 10));

	fl_rect = bevel->getGlobalBounds();
}

void text::render(RenderWindow& wd) noexcept {
	if (visible) {
		if (visible_bevel) {
			wd.draw(*bevel);
		}
		wd.draw(*label);
	}
}

void text::render(RenderWindow* wd) noexcept {
	if (visible) {
		if (visible_bevel) {
			wd->draw(*bevel);
		}
		wd->draw(*label);
	}
}
//-----------------------------------Текст-text-Конец-------------------------------------

//-----------------------------Коллизия-Collision-Начало---------------------------------------
Collision::Collision(const IntRect& rect) :
	active(true),
	visible_deb(false)
{
	pos.x = rect.left;
	pos.y = rect.top;
	rect_collis = rect;

	main = new RectangleShape;
	main->setPosition(Vector2f(rect_collis.left, rect_collis.top));
	main->setSize(Vector2f(rect_collis.width, rect_collis.height));
	main->setFillColor(Color::Red);
}

Collision::~Collision() {
	//main->~RectangleShape();
	delete main;
}

void __fastcall Collision::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;

	rect_collis.left = pos.x;
	rect_collis.top = pos.y;
	main->setPosition(Vector2f(pos.x, pos.y));
}

void Collision::setPosition(const axes_i& xy) {
	pos = xy;

	rect_collis.left = pos.x;
	rect_collis.top = pos.y;
	main->setPosition(Vector2f(pos.x, pos.y));
}

axes_i Collision::getPosition() {
	return pos;
}

IntRect Collision::getBounds() {
	return rect_collis;
}

void Collision::setBounds(const IntRect& rect) {
	pos.x = rect.left;
	pos.y = rect.top;
	rect_collis = rect;
	main->setSize(Vector2f(rect_collis.width, rect_collis.height));
	main->setPosition(Vector2f(rect_collis.left, rect_collis.top));
}

void Collision::render(RenderWindow& wd) {
	if (visible_deb) {
		wd.draw(*main);
	}
}

void Collision::render(RenderWindow* wd) {
	if (visible_deb) {
		wd->draw(*main);
	}
}
//-----------------------------Коллизия-Collision-Конец----------------------------------------

//---------------------------Статический-объект-ObjectStatic-Начало------------------------------
ObjectStatic::ObjectStatic(Texture* ptr_texture, float X, float Y) {
	pos.x = X;
	pos.y = Y;

	sprt = new Sprite;
	sprt->setTexture(*ptr_texture);
	sprt->setTextureRect(IntRect(0, 0, ptr_texture->getSize().x, ptr_texture->getSize().y));
	sprt->setPosition(pos.x, pos.y);

	react_obj_stat = sprt->getGlobalBounds();

	rect_collis = new Collision(IntRect(0, 0, 0, 0));
}

ObjectStatic::~ObjectStatic() {
	delete sprt;
	delete rect_collis;
}

axes_i ObjectStatic::getPosition() {
	return pos;
}

FloatRect ObjectStatic::getSize() {
	return sprt->getGlobalBounds();//react_obj_stat;
}

void ObjectStatic::setRect(const IntRect& bound) {
	sprt->setTextureRect(IntRect(bound.left, bound.top, bound.width, bound.height));
}

void __fastcall ObjectStatic::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;

	sprt->setPosition(pos.x, pos.y);

	react_obj_stat = sprt->getGlobalBounds();
}

void ObjectStatic::setPosition(const axes_i& xy) {
	pos = xy;

	sprt->setPosition(pos.x, pos.y);

	react_obj_stat = sprt->getGlobalBounds();
}

void ObjectStatic::render(RenderWindow& wd) {
	wd.draw(*sprt);
}

void ObjectStatic::render(RenderWindow* wd) {
	wd->draw(*sprt);
}
//----------------------------------Статический-объект-ObjectStatic-Конец-------------------------------

//-------------------------------Анимированный-объект-ObjectAnimated-Начало------------------------------
ObjectAnimated::ObjectAnimated(Texture* ptr_texture, float X, float Y) :
	frame(0),
	end(false),
	ObjectStatic(ptr_texture, X, Y) 
{

}

ObjectAnimated::~ObjectAnimated() {}

void __fastcall ObjectAnimated::update(float time) {}
//-------------------------------Анимированный-объект-ObjectAnimated-Конец-------------------------------

//--------------------------------------Метеорит-Meteor-Начало------------------------------------
Meteor::Meteor(Texture* ptr_texture, Texture* ptr_texture2, float X, float Y) :   
	cooldown(false),
	reached_point(false),
	current_len(0),
	ObjectAnimated(ptr_texture, X, Y)
{
	sprt_meteor = new Sprite;
	sprt_meteor->setTexture(*ptr_texture2);

	sprt->setTextureRect(IntRect(400, 0, ptr_texture->getSize().x, ptr_texture->getSize().y));
	sprt->setPosition(pos.x, pos.y);

	react_obj_stat = sprt->getGlobalBounds();
	
	rect_collis->setBounds(IntRect(pos.x, pos.y, 400, 400));

	mouse_point.x = X + 200;
	mouse_point.y = Y + 200;

	start_point.x = mouse_point.x - 270;
	start_point.y = mouse_point.y - 1440;
}

Meteor::~Meteor() {
	delete sprt_meteor;
}

void __fastcall Meteor::update(float time) {
	
	isReachedPoint(time);

	if (reached_point) {
		frame += 0.022 * time;
		if (frame > 24) {
			end = true;
		}

		if (frame >= 0 && frame <= 5) {
			sprt->setTextureRect(IntRect(400 * int(frame), 0, 400, 400));
		}
		else if (frame >= 6 && frame <= 11) {
			sprt->setTextureRect(IntRect(400 * (int(frame) - 6), 400, 400, 400));
		}
		else if (frame >= 12 && frame <= 17) {
			sprt->setTextureRect(IntRect(400 * (int(frame) - 12), 800, 400, 400));
		}
		else if (frame >= 18 && frame <= 23) {
			sprt->setTextureRect(IntRect(400 * (int(frame) - 18), 1200, 400, 400));
		}
		react_obj_stat = sprt->getGlobalBounds();
	}
}

void Meteor::isReachedPoint(float time) {
	float full_len = sqrt(pow(mouse_point.x - start_point.x, 2) + pow(mouse_point.y - start_point.y, 2));	
	Vector2f C;

	if (current_len < full_len) {
		C = (mouse_point - start_point);
		C.x = C.x * (current_len / full_len);
		C.y = C.y * (current_len / full_len);
		C = start_point + C;
		sprt_meteor->setPosition(C.x - (sprt_meteor->getGlobalBounds().width / 2), C.y - (sprt_meteor->getGlobalBounds().height / 2));
		current_len +=  3.f * time;
	} else {
		reached_point = true;
	}
}

void Meteor::render(RenderWindow& wd) {
	if (reached_point) {
		wd.draw(*sprt);
	} else {
		wd.draw(*sprt_meteor);
	}	
}

void Meteor::render(RenderWindow* wd) {
	if (reached_point) {
		wd->draw(*sprt);
	} else {
		wd->draw(*sprt_meteor);
	}	
}
//--------------------------------------Метеорит-Meteor-Конец------------------------------------

//-----------------------------Мини-полоса-min_bar-Начало----------------------------------------
min_bar::min_bar(int x, int y, int br_ma, int br_mi, const Color& mcol, const Color& bcol) :
	BaseInerface(x, y, FloatRect(Vector2f(0, 0), Vector2f(0, 0))),
	max_br(br_ma),
	min_br(br_mi),
	curr_br(br_ma)
{
	main = new RectangleShape;
	main->setSize(Vector2f(150, 9));
	main->setFillColor(mcol);
	main->setPosition(pos.x, pos.y);

	bevel = new RectangleShape;
	bevel->setSize(Vector2f(main->getGlobalBounds().width - 6, main->getGlobalBounds().height - 6));
	bevel->setFillColor(bcol);
	bevel->setPosition(pos.x + 3, pos.y + 3);

	fl_rect = main->getGlobalBounds();
}

min_bar::~min_bar() {
	delete main, bevel;
}

void __fastcall min_bar::setPosition(int x, int y) noexcept {
	pos.x = x;
	pos.y = y;

	main->setPosition(pos.x, pos.y);
	bevel->setPosition(pos.x + 3, pos.y + 3);
	fl_rect = main->getGlobalBounds();
}

void min_bar::setPosition(const axes_i& xy) noexcept {
	pos = xy;

	main->setPosition(pos.x, pos.y);
	bevel->setPosition(pos.x + 3, pos.y + 3);
	fl_rect = main->getGlobalBounds();
}

void  min_bar::changeBar(int arg) noexcept {
	if (curr_br != arg) {
		if (arg < 0) {
			arg = 0;
		}
		bevel->setSize(Vector2f((144 * arg) / max_br, 3));
		curr_br = arg;
	}
}

void min_bar::render(RenderWindow& wd) noexcept {
	if (visible) {
		wd.draw(*main);
		wd.draw(*bevel);
	}
}

void min_bar::render(RenderWindow* wd) noexcept {
	if (visible) {
		wd->draw(*main);
		wd->draw(*bevel);
	}
}
//-----------------------------Мини-полоса-min_bar-Конец-----------------------------------------

//--------------------------------База-Характера-BaseCharacter-Начало------------------------------------------
BaseCharacter::BaseCharacter() :
	pos(axes_f(0, 0)),
	health(0),
	visible(true),
	cooldown(false),
	isDead(false),
	zeroing(false),
	timer_cooldown(0),
	frame(0),
	id_class(BASECLASS)
{
}

BaseCharacter::BaseCharacter(const Sprite &ptr_sprite, float x, float y, int _hp, unsigned int id) :
	pos(x, y),
	health(_hp),
	visible(true),
	cooldown(false),
	isDead(false),
	zeroing(false),
	timer_cooldown(0),
	frame(0),
	id_class(id)
{
	sprite_rect = static_cast<IntRect>(ptr_sprite.getGlobalBounds());
}

BaseCharacter::BaseCharacter(const Sprite &ptr_sprite, const axes_f& xy, int _hp, unsigned int id) :
	pos(xy),
	health(_hp),
	visible(true),
	cooldown(false),
	isDead(false),
	zeroing(false),
	timer_cooldown(0),
	frame(0),
	id_class(id)
{
	sprite_rect = static_cast<IntRect>(ptr_sprite.getGlobalBounds());
}

BaseCharacter::~BaseCharacter() {}

axes_f BaseCharacter::getPosition() {
	return pos;
}

IntRect BaseCharacter::getSize() {
	return sprite_rect;
}

void BaseCharacter::setPosition(float x, float y) {
	pos.x = x;
	pos.y = y;
}

void BaseCharacter::setPosition(const axes_f& xy) {
	pos = xy;
}

void __fastcall BaseCharacter::move(float time, int direct) noexcept {

}

void BaseCharacter::render(RenderWindow& wd, Sprite *ptr_sprite) {
	if (visible) {
		ptr_sprite->setPosition(pos.x, pos.y);
		ptr_sprite->setTextureRect(sprite_rect);
		wd.draw(*ptr_sprite);
	}
}

void BaseCharacter::render(RenderWindow* wd, Sprite *ptr_sprite) {
	if (visible) {
		ptr_sprite->setPosition(pos.x, pos.y);
		ptr_sprite->setTextureRect(sprite_rect);
		wd->draw(*ptr_sprite);
	}
}
//--------------------------------База-Характера-BaseCharacter-Конец------------------------------------------

//-----------------------------------------Копейщик-Spearman-Начало------------------------------------------
Spearman::Spearman(const Sprite &ptr_sprite, float X_POS, float Y_POS, int hp, unsigned int id) :
	BaseCharacter(ptr_sprite, X_POS, Y_POS, hp, id)
{
	direction = 0;
	last_direction = direction;
	sprite_rect = IntRect(300 * int(frame), 0, 300, 180);
	rect_collis = new Collision(IntRect(pos.x + 15, pos.y, abs(sprite_rect.width) - 30, abs(sprite_rect.height)));
	HP = new min_bar(pos.x + (sprite_rect.width / 2), pos.y + sprite_rect.height, health, 0, Color::Black, Color::Red);
}

Spearman::~Spearman() {
	delete rect_collis, HP;
}

void __fastcall Spearman::setPosition(float x, float y) noexcept {
	pos.x = x;
	pos.y = y;
	rect_collis->setPosition(pos.x + 15, pos.y);
	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2) + 20, pos.y + abs(sprite_rect.height));
}

void Spearman::setPosition(const axes_f& xy) noexcept {
	pos = xy;
	rect_collis->setPosition(pos.x + 15, pos.y);
	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2) + 20, pos.y + abs(sprite_rect.height));
}

void __fastcall Spearman::move(float time, int direct) noexcept {
	direction = direct;

	if (health <= 0 && !zeroing) {
		zeroing = true;
		frame = 0;
	}

	if (health <= 0) {
		frame += 0.023 * time;
		if (frame > 7) {
			frame = 6;
			isDead = true;
		}
		sprite_rect = IntRect(300 * int(frame) + 300, 360, -300, 180);
	} else {
		switch (direction) { //Направление движения
		case direcrion8::right:
			frame += 0.023 * time;
			if (frame > 7) {
				frame = 0;
			}
			sprite_rect = IntRect(300 * int(frame), 0, 300, 180);
			pos.x = pos.x + (0.5 * time); 
		case direcrion8::left:
			frame += 0.023 * time;
			if (frame > 7) {
				frame = 0;
			}
			sprite_rect = IntRect(300 * int(frame) + 300, 0, -300, 180); 
			pos.x = pos.x + (-0.5 * time);
		default:
			break;
		}
	}
	last_direction = direction;
	direction = 0;
	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2) + 20, pos.y + abs(sprite_rect.height));
	rect_collis->setPosition(pos.x + 15, pos.y);
}

void __fastcall Spearman::attack(float time) {
	if (health <= 0 && !zeroing) {
		zeroing = true;
		frame = 0;
	}

	if (health <= 0) {
		frame += 0.023 * time;
		if (frame > 7) {
			frame = 6;
			isDead = true;
		}
		sprite_rect = IntRect(300 * int(frame) + 300, 360, -300, 180); 
	} else {
		frame += 0.023 * time;
		if (frame > 6) {
			frame = 0;
		}
		sprite_rect = IntRect(300 * int(frame) + 300, 180, -300, 180); 
	}
}

bool Spearman::isCooldown(float time) {
	if (!cooldown) {
		timer_cooldown = 0;
		return false;
	} else {
		timer_cooldown += time;
		if (timer_cooldown >= 2) {
			cooldown = false;
			timer_cooldown = 0;
			return false;
		}
		cooldown = true;
		return true;
	}
}

void Spearman::render(RenderWindow& wd, Sprite *ptr_sprite) noexcept {
	rect_collis->render(wd);
	ptr_sprite->setPosition(pos.x, pos.y);
	ptr_sprite->setTextureRect(sprite_rect);
	wd.draw(*ptr_sprite);
	HP->changeBar(health);
	HP->render(wd);
}

void Spearman::render(RenderWindow* wd, Sprite *ptr_sprite) noexcept {
	rect_collis->render(wd);
	ptr_sprite->setPosition(pos.x, pos.y);
	ptr_sprite->setTextureRect(sprite_rect);
	wd->draw(*ptr_sprite);
	HP->changeBar(health);
	HP->render(wd);
}
//------------------------------------------Копейщик-Spearman-Конец------------------------------------------

//-----------------------------------Разрушитель-замков-DestroerCastle-Начало-----------------------------------------
DestroerCastle::DestroerCastle(const Sprite &ptr_sprite, float X_POS, float Y_POS, int hp, unsigned int id) :
	BaseCharacter(ptr_sprite, X_POS, Y_POS, hp, id)
{

	direction = 0;
	last_direction = direction;
	sprite_rect = IntRect(0, 0, 600, 350);
	rect_collis = new Collision(IntRect(pos.x, pos.y, abs(sprite_rect.width), abs(sprite_rect.height)));
	HP = new min_bar(pos.x + (abs(sprite_rect.width) / 2), pos.y + abs(sprite_rect.top), health, 0, Color::Black, Color::Red);
}

DestroerCastle::~DestroerCastle() {
	delete HP;
	delete rect_collis;
}

void __fastcall DestroerCastle::setPosition(float x, float y) noexcept {
	pos.x = x;
	pos.y = y;
	rect_collis->setPosition(pos.x, pos.y);
	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2), pos.y + abs(sprite_rect.height));
}

void DestroerCastle::setPosition(const axes_f& xy) noexcept {
	pos = xy;
	rect_collis->setPosition(pos.x, pos.y);
	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2), pos.y + abs(sprite_rect.height));
}

void __fastcall DestroerCastle::move(float time, int direct) noexcept {
	direction = direct;

	if (health <= 0 && !zeroing) {
		zeroing = true;
		frame = 0;
	}

	if (health <= 0) {
		frame += 0.023 * time;
		if (frame > 6) {
			frame = 5;
			isDead = true;
		}
		sprite_rect = IntRect(600 * int(frame), 700, 600, 350);
	} else {
		switch (direction) { //Направление движения
		case direcrion8::right:
			frame += 0.023 * time;
			if (frame > 4) {
				frame = 0;
			}
			sprite_rect = IntRect(600 * int(frame) + 600, 0, -600, 350); 
			pos.x = pos.x + (0.5 * time); 
		case direcrion8::left:
			frame += 0.023 * time;
			if (frame > 4) {
				frame = 0;
			}
			sprite_rect = IntRect(600 * int(frame), 0, 600, 350); 
			pos.x = pos.x + (-0.5 * time); 
		default:
			break;
		}
	}
	last_direction = direction;
	direction = 0;
	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2), pos.y + abs(sprite_rect.height));
	rect_collis->setPosition(pos.x, pos.y);
}

void __fastcall DestroerCastle::attack(float time) {
	if (health <= 0 && !zeroing) {
		zeroing = true;
		frame = 0;
	}

	if (health <= 0) {
		frame += 0.023 * time;
		if (frame > 6) {
			frame = 5;
			isDead = true;
		}
		sprite_rect = IntRect(600 * int(frame), 700, 600, 350); 
	} else {
		frame += 0.023 * time;
		if (frame > 6) {
			frame = 0;
		}
		sprite_rect = IntRect(600 * int(frame), 350, 600, 350); 
	}
}

bool DestroerCastle::isCooldown(float time) {
	if (!cooldown) {
		timer_cooldown = 0;
		return false;
	} else {
		timer_cooldown += time;
		if (timer_cooldown >= 3) {
			cooldown = false;
			timer_cooldown = 0;
			return false;
		}
		cooldown = true;
		return true;
	}
}

void DestroerCastle::render(RenderWindow& wd, Sprite *ptr_sprite) noexcept {
	rect_collis->render(wd);
	ptr_sprite->setPosition(pos.x, pos.y);
	ptr_sprite->setTextureRect(sprite_rect);
	wd.draw(*ptr_sprite);
	HP->changeBar(health);
	HP->render(wd);
}

void DestroerCastle::render(RenderWindow* wd, Sprite *ptr_sprite) noexcept {
	rect_collis->render(wd);
	ptr_sprite->setPosition(pos.x, pos.y);
	ptr_sprite->setTextureRect(sprite_rect);
	wd->draw(*ptr_sprite);
	HP->changeBar(health);
	HP->render(wd);
}
//-----------------------------------Разрушитель-замков-DestroerCastle-Конец------------------------------------------

// ----------------------------------Персанаж-Character-Начало------------------------------
Character::Character(const Sprite &ptr_sprite, float X_POS, float Y_POS, int hp, unsigned int id) :
	BaseCharacter(ptr_sprite, X_POS, Y_POS, hp, id)
{
	direction = 0;
	last_direction = direction;
	sprite_rect = IntRect(400 * int(frame), 250, 300, 250);
	rect_collis = new Collision(IntRect(pos.x, pos.y, abs(sprite_rect.width) - 20, abs(sprite_rect.height) - 20));
	HP = new min_bar(pos.x + (abs(sprite_rect.width) / 2), pos.y + abs(sprite_rect.height), health, 0, Color::Black, Color::Red);
}

Character::~Character() {
	delete HP;
}

void __fastcall Character::setPosition(float x, float y) noexcept {
	pos.x = x;
	pos.y = y;
	rect_collis->setPosition(pos.x, pos.y);
	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2) + 25, pos.y + abs(sprite_rect.height));
}

void Character::setPosition(const axes_f& xy) noexcept {
	pos = xy;
	rect_collis->setPosition(pos.x, pos.y);
	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2) + 25, pos.y + abs(sprite_rect.height));
}

void __fastcall Character::move(float time, int direct) noexcept {
	direction = direct;

	if (health <= 0 && !zeroing) {
		zeroing = true;
		frame = 0;
	}

	if (health <= 0) {
		frame += 0.04 * time;
		if (frame > 7) {
			frame = 6;
			isDead = true;
		}
		sprite_rect = IntRect(400 * int(frame) + 400, 0, -400, 250); 
	} else {
		switch (direction) { 
		case direcrion8::right:
			frame += 0.023 * time;
			if (frame > 7) {
				frame = 0;
			}
			sprite_rect = IntRect(400 * int(frame), 250, 400, 250); 
			pos.x = pos.x + (0.5 * time); 
		case direcrion8::left:
			frame += 0.023 * time;
			if (frame > 7) {
				frame = 0;
			}
			sprite_rect = IntRect(400 * int(frame) + 400, 250, -400, 250);
			pos.x = pos.x + (-0.5 * time);
		default: break;
		}
	}
	last_direction = direction;
	direction = 0;

	HP->setPosition(pos.x + (abs(sprite_rect.width) / 2) - (HP->getSize().width / 2) + 25, pos.y + abs(sprite_rect.height));
	rect_collis->setPosition(pos.x + 100, pos.y + 20);
}

void __fastcall Character::attack(float time) {
	if (health <= 0 && !zeroing) {
		zeroing = true;
		frame = 0;
	}

	if (health <= 0) {
		frame += 0.023 * time;
		if (frame > 7) {
			frame = 6;
			isDead = true;
		}
		sprite_rect = IntRect(400 * int(frame) + 400, 0, -400, 250);
	} else {
		frame += 0.023 * time;
		if (frame > 7) {
			frame = 0;
		}
		sprite_rect = IntRect(400 * int(frame) + 400, 500, -400, 250);
	}
}

bool Character::isCooldown(float time) {
	if (!cooldown) {
		timer_cooldown = 0;
		return false;
	} else {
		timer_cooldown += time;
		if (timer_cooldown >= 3) {
			cooldown = false;
			timer_cooldown = 0;
			return false;
		}
		cooldown = true;
		return true;
	}
}

void Character::render(RenderWindow& wd, Sprite *ptr_sprite) noexcept {
	rect_collis->render(wd);
	ptr_sprite->setPosition(pos.x, pos.y);
	ptr_sprite->setTextureRect(sprite_rect);
	wd.draw(*ptr_sprite);
	HP->changeBar(health);
	HP->render(wd);
}

void Character::render(RenderWindow* wd, Sprite *ptr_sprite) noexcept {
	rect_collis->render(wd);
	ptr_sprite->setPosition(pos.x, pos.y);
	ptr_sprite->setTextureRect(sprite_rect);
	wd->draw(*ptr_sprite);
	HP->changeBar(health);
	HP->render(wd);
}
//----------------------------------Персанаж-Character-Конец------------------------------

text_chr::text_chr(int x = 0, int y = 0, std::wstring txt = L"ERR:", Color lbcol = Color::White, Color bvcol = Color::Black) :
	BaseInerface(x, y, FloatRect(Vector2f(0, 0), Vector2f(0, 0))),
	real_pos(axes_f(x, y)),
	visible_bevel(true),
	cl_char(lbcol),
	cl_back(bvcol),
	buff_ident(0),
	line(0),
	size(10),
	size_m(0)
{
#undef small
	font_main = new Font;
	font_main->loadFromFile("fonts/GnuUnifontFull-Pm9P.ttf");
	
	caption = nullptr;
	*/
	/*caption = new std::vector<elem_str*>;

	for (int i = 0; i < txt.length(); i++) {
		caption->push_back(new elem_str);
		(*caption)[i]->cl_symbl = cl_char;
		(*caption)[i]->symbl = txt[i];
		(*caption)[i]->ident_y = 0;
	}*/
/*
	bevel = new RectangleShape;
	bevel->setFillColor(cl_back);
	bevel->setPosition(pos.x, pos.y);
	fl_rect = bevel->getGlobalBounds();

	label = new sf::Text;
	label->setFont(*font_main);
	label->setPosition(0, 0);
#define small char
}

text_chr::text_chr(int x, int y, Color lbcol, Color bvcol) : 
	BaseInerface(x, y, FloatRect(Vector2f(0, 0), Vector2f(0, 0))),
	real_pos(axes_f(x, y)),
	visible_bevel(false),
	cl_char(lbcol),
	cl_back(bvcol),
	buff_ident(0),
	line(0),
	size(10),
	size_m(0)
{
	font_main = new Font;
	font_main->loadFromFile("fonts/GnuUnifontFull-Pm9P.ttf");
	
	caption = nullptr;
	
	//caption = new std::vector<elem_str*>;

	bevel = new RectangleShape;
	bevel->setFillColor(cl_back);
	bevel->setPosition(pos.x, pos.y);
	fl_rect = bevel->getGlobalBounds();

	label = new sf::Text;
	label->setFont(*font_main);
	label->setPosition(0, 0);
}

text_chr::~text_chr() {*/
	/*for (std::vector<elem_str*>::iterator it = caption->begin(); it != caption->end();) {
		delete *(it);
		it = caption->erase(it);
	}*/
	/*delete font_main, bevel, label, point;

	if (size_m != 0) {
		delete[] caption;
	}
}

void text_chr::addWChar(wchar_t symb) {*/
	/*caption->push_back(new elem_str);
	caption->back()->cl_symbl = cl_char;
	caption->back()->symbl = symb;
	caption->back()->ident_y = line;*/
//}

//void text_chr::add32Char(char32_t symb) {
	

	
	/*caption->push_back(new elem_str);
	caption->back()->cl_symbl = cl_char;
	caption->back()->symbl = symb;
	caption->back()->ident_y = line;*/
//}

//void text_chr::setString(std::wstring txt) noexcept {
	/*for (int i = 0; i < txt.length(); i++) {
		caption->push_back(new elem_str);
		(*caption)[i]->cl_symbl = cl_char;
		(*caption)[i]->symbl = txt[i];
	}*/
//}

//void text_chr::setString(sf::String txt) noexcept {
	/*for (int i = 0; i < txt.getSize(); i++) {
		caption->push_back(new elem_str);
		(*caption)[i]->cl_symbl = cl_char;
		(*caption)[i]->symbl = txt[i];
	}*/
//}

/*void text_chr::setFont(String txt) noexcept {
	font_main->loadFromFile(txt);
}

void text_chr::setPosition(const axes_i& xy) noexcept {*/
	/*pos = xy;
	bevel->setPosition(pos.x, pos.y);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));

	fl_rect = bevel->getGlobalBounds();*/
//}

//void __fastcall text_chr::setPosition(int x, int y) noexcept {
	/*pos.x = x;
	pos.y = y;
	bevel->setPosition(pos.x, pos.y);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));

	fl_rect = bevel->getGlobalBounds();*/
//}

//void text_chr::resize(int size = normal) noexcept {
	/*label->setCharacterSize(size);
	label->setPosition(pos.x, pos.y);
	label->setPosition(repoz_x(int, pos.x, label->getGlobalBounds().left, 5), repoz_y(int, pos.y, label->getGlobalBounds().top, 5));
	bevel->setSize(Vector2f(label->getGlobalBounds().width + 10, label->getGlobalBounds().height + 10));

	fl_rect = bevel->getGlobalBounds();*/
//}

/*void text_chr::render(RenderWindow& wd) noexcept {
	buff_ident = 0;
	if (visible) {
		for (int i = 0, fl_line = (caption + 0)->ident_y; i < size_m; i++) {
			point.color = (caption + i)->cl_symbl;
			if (fl_line < (caption + i)->ident_y) {
				buff_ident = 0;
				fl_line = (caption + i)->ident_y;
			}
			point.position = Vector2f(pos.x + (buff_ident * 2), pos.y + (fl_line * 2));//label->setPosition(repoz_x(float, pos.x, label->getGlobalBounds().left, 0 + buff_ident), repoz_y(float, pos.y + ((caption + i)->ident_y * ((size / 2) - 1)), label->getGlobalBounds().top, 0));
			buff_ident++;//buff_ident += label->getGlobalBounds().width;
	
			wd.draw(&point, 1, sf::PrimitiveType::Points);
		}
	}*/

	/*
		if (visible) {
		for (int i = 0, fl_line = (caption + 0)->ident_y; i < size_m; i++) {
			label->setFillColor((caption + i)->cl_symbl);
			//label->setString((caption + i)->symbl);
			label->setCharacterSize(size);
			label->setPosition(0, 0);
			if (fl_line < (caption + i)->ident_y) {
				buff_ident = 0;
				fl_line = (caption + i)->ident_y;
			}

			if (i == 0) {
				label->setPosition(repoz_x(float, pos.x, label->getGlobalBounds().left, 0), repoz_y(float, pos.y, label->getGlobalBounds().top, 0));
				buff_ident = label->getGlobalBounds().width;
			} else {
				label->setPosition(repoz_x(float, pos.x, label->getGlobalBounds().left, 0 + buff_ident), repoz_y(float, pos.y + ((caption + i)->ident_y * ((size / 2) - 1)), label->getGlobalBounds().top, 0));
				buff_ident += label->getGlobalBounds().width;
			}
			wd.draw(*label);
		}
	}
	*/
//}

/*void text_chr::render(RenderWindow* wd) noexcept {
}

void text_chr::newline() {
	line++;
}

void text_chr::clear() {
	pos.y = real_pos.x;
	buff_ident = 0;
	if (size_m != 0) {
		delete[] caption;
	}
	size_m = 0;

}

void text_chr::malloc_arr(size_t size) {
	size_m = size;
	caption = new elem_str[size];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------Градиент-gradient-Начало---------------------------------------
gradient::gradient(const FloatRect &rt, gradient_direction gd, const Color &first, const Color &second) :
	BaseInerface(0, 0, rt)
	{
	rect = new sf::VertexArray;

	pos.x = fl_rect.left; 
	pos.y = fl_rect.top;

	rect->setPrimitiveType(sf::Quads);
	
	switch (gd) {
		case leftOnRight:
			for (int i = 0; i < 2; i++) {
				colors.push_back(second);
				colors.push_back(first);
			}
			break;
		case rightOnLeft:
			for (int i = 0; i < 2; i++) {
				colors.push_back(first);
				colors.push_back(second);
			}
			break;
		case topOnBottom:
			colors.push_back(first);
			colors.push_back(first);
			colors.push_back(second);
			colors.push_back(second);
			break;
		case bottomOnTop:
			colors.push_back(second);
			colors.push_back(second);
			colors.push_back(first);
			colors.push_back(first);
			break;
		default:
			break;
	}

	rect->append(sf::Vertex(sf::Vector2f(fl_rect.left, fl_rect.top), colors[0]));
	rect->append(sf::Vertex(sf::Vector2f(fl_rect.left + fl_rect.width, fl_rect.top), colors[1]));
	rect->append(sf::Vertex(sf::Vector2f(fl_rect.left + fl_rect.width, fl_rect.top + fl_rect.height), colors[3]));
	rect->append(sf::Vertex(sf::Vector2f(fl_rect.left, fl_rect.top + fl_rect.height), colors[2]));
}

gradient::~gradient() {
	delete rect;
}

void gradient::setPosition(const axes_i &xy) {
	pos = xy;

	rect->clear();

	rect->append(sf::Vertex(sf::Vector2f(pos.x, pos.y), colors[0]));
	rect->append(sf::Vertex(sf::Vector2f(pos.x + fl_rect.width, pos.y), colors[1]));
	rect->append(sf::Vertex(sf::Vector2f(pos.x + fl_rect.width, pos.y + fl_rect.height), colors[3]));
	rect->append(sf::Vertex(sf::Vector2f(pos.x, pos.y + fl_rect.height), colors[2]));
}

void __fastcall gradient::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;

	rect->clear();

	rect->append(sf::Vertex(sf::Vector2f(pos.x, pos.y), colors[0]));
	rect->append(sf::Vertex(sf::Vector2f(pos.x + fl_rect.width, pos.y), colors[1]));
	rect->append(sf::Vertex(sf::Vector2f(pos.x + fl_rect.width, pos.y + fl_rect.height), colors[3]));
	rect->append(sf::Vertex(sf::Vector2f(pos.x, pos.y + fl_rect.height), colors[2]));
}

void gradient::render(RenderWindow &wd) noexcept {
	if (visible) {
		wd.draw(*rect);
	}
}
//-------------------------------Градиент-gradient-Конец---------------------------------------

//-----------------------------------Кнопка-button-Начало-------------------------------------
button::button(int x, int y, const Font &font, const wchar_t *text, const Color &maincl, const Color &textcl, const Color &activecl) :
	BaseInerface(x, y, FloatRect(Vector2f(0, 0), Vector2f(0, 0))),
	active(false)
	{
	pos.x = x;
	pos.y = y;

	txt = new Text;
	txt->setFont(font);
	txt->setString(text);
	txt->setCharacterSize(24);

	txt->setFillColor(textcl);
	txt->setPosition(pos.x, pos.y);
	txt->setPosition(repoz_x(int, pos.x, txt->getGlobalBounds().left, 5), repoz_y(int, pos.y, txt->getGlobalBounds().top, 5));

	main = new RectangleShape;
	main->setSize(Vector2f(txt->getGlobalBounds().width + 10, txt->getGlobalBounds().height + 10));
	main->setFillColor(maincl);
	main->setPosition(pos.x, pos.y);

	active_bvl = new RectangleShape;
	active_bvl->setSize(Vector2f(main->getGlobalBounds().width + 10, main->getGlobalBounds().height + 10));
	active_bvl->setFillColor(activecl);
	active_bvl->setPosition(pos.x - 5, pos.y - 5);

	fl_rect = main->getGlobalBounds();
}

button::~button() {
	delete main, active_bvl, txt;
}

void button::setPosition(const axes_i &xy) {
	pos = xy;
	txt->setPosition(pos.x, pos.y);
	txt->setPosition(repoz_x(int, pos.x, txt->getGlobalBounds().left, 5), repoz_y(int, pos.y, txt->getGlobalBounds().top, 5));
	main->setPosition(pos.x, pos.y);
	active_bvl->setPosition(pos.x - 5, pos.y - 5);
	fl_rect = main->getGlobalBounds();
}

void __fastcall button::setPosition(int x, int y) {
	pos.x = x;
	pos.y = y;
	txt->setPosition(pos.x, pos.y);
	txt->setPosition(repoz_x(int, pos.x, txt->getGlobalBounds().left, 5), repoz_y(int, pos.y, txt->getGlobalBounds().top, 5));
	main->setPosition(pos.x, pos.y);
	active_bvl->setPosition(pos.x - 5, pos.y - 5);
	fl_rect = main->getGlobalBounds();
}

void button::render(RenderWindow &wd) noexcept {
	if (visible) {
		if (active) {
			wd.draw(*active_bvl);
		}
		wd.draw(*main);
		wd.draw(*txt);
	}
}

void button::resize(int size) {
	txt->setCharacterSize(size);
	txt->setPosition(pos.x, pos.y);
	txt->setPosition(repoz_x(int, pos.x, txt->getGlobalBounds().left, 5), repoz_y(int, pos.y, txt->getGlobalBounds().top, 5));
	main->setSize(Vector2f(txt->getGlobalBounds().width + 10, txt->getGlobalBounds().height + 10));
	active_bvl->setSize(Vector2f(main->getGlobalBounds().width + 10, main->getGlobalBounds().height + 10));
	fl_rect = main->getGlobalBounds();
}

bool __fastcall button::isAction(int x, int y) {
	fl_rect.contains(x, y) ? active = true : active = false;
	return active;
}

bool button::isAction(const axes_i &xy) {
	fl_rect.contains(xy.x, xy.y) ? active = true : active = false;
	return active;
}
//-----------------------------------Кнопка-button-Конец--------------------------------------

message::message(int x, int y, const Font& font, const wchar_t* txt, const Color& maincl, const Color& bordercl, const Color& textcl) :
	active(false)
{
	pos.x = x;
	pos.y = y;

	main = new RectangleShape;
	//main_cl = new Color;
	//*main_cl = maincl;
	main->setFillColor(maincl);

	border = new RectangleShape;
	//border_cl = new Color;
	//*border_cl = bordercl;
	border->setFillColor(bordercl);

	txInfo = new text(0, 0, txt, textcl);
	txInfo->visible_bevel = false;
	txMess = new text(0, 0, L"Сообщение", Color::Yellow);
	txMess->visible_bevel = false;

	main->setSize(Vector2f(txInfo->getSize().width + 10, 150));
	border->setSize(Vector2f(main->getGlobalBounds().width + 10, main->getGlobalBounds().height + 10));

	main->setPosition(pos.x - main->getGlobalBounds().width / 2, pos.y - main->getGlobalBounds().height / 2);
	border->setPosition(main->getGlobalBounds().left - 5, main->getGlobalBounds().top - 5);

	txInfo->setPosition(main->getGlobalBounds().left + (main->getGlobalBounds().width / 2) - (txInfo->getSize().width / 2), main->getGlobalBounds().top + 10);
	txMess->setPosition(main->getGlobalBounds().left + (main->getGlobalBounds().width / 2) - (txMess->getSize().width / 2), main->getGlobalBounds().top + main->getGlobalBounds().height - 50);
	grFirst = new gradient(FloatRect(Vector2f(0, 0), Vector2f(150, 5)), gradient_direction::rightOnLeft, Color::Transparent, Color::Yellow);
	grSecond = new gradient(FloatRect(Vector2f(0, 0), Vector2f(150, 5)), gradient_direction::leftOnRight, Color::Transparent, Color::Yellow);

	grFirst->setPosition(txMess->getPosition().x - 5 - grFirst->getSize().width, txMess->getPosition().y + (txMess->getSize().height / 2) - (grFirst->getSize().height / 2));
	grSecond->setPosition(txMess->getPosition().x + 5 + txMess->getSize().width, txMess->getPosition().y + (txMess->getSize().height / 2) - (grSecond->getSize().height / 2));

	btOk = new button(0, 0, font, L"Ок", Color::Black, Color::Yellow, Color::Yellow);
	btOk->setPosition(main->getGlobalBounds().left + (main->getGlobalBounds().width / 2) - (btOk->getSize().width / 2), txMess->getSize().top - 35);
}

message::~message() {
	delete main, border;
	delete txInfo, txMess;
	delete grFirst, grSecond;
	delete btOk;
}*/

/*void message::render(RenderWindow& wd, Camer* camera) noexcept {
	if (active) {
		pos = camera->getPosition();

		main->setPosition(pos.x - main->getGlobalBounds().width / 2, pos.y - main->getGlobalBounds().height / 2);
		border->setPosition(pos.x - 5 - main->getGlobalBounds().width / 2, pos.y - 5 - main->getGlobalBounds().height / 2);
		txInfo->setPosition(main->getGlobalBounds().left + (main->getGlobalBounds().width / 2) - (txInfo->getSize().width / 2), main->getGlobalBounds().top + 10);
		txMess->setPosition(main->getGlobalBounds().left + (main->getGlobalBounds().width / 2) - (txMess->getSize().width / 2), main->getGlobalBounds().top + main->getGlobalBounds().height - 50);
		btOk->setPosition(main->getGlobalBounds().left + (main->getGlobalBounds().width / 2) - (btOk->getSize().width / 2), txInfo->getSize().top + txInfo->getSize().height + 20);
		grFirst->setPosition(txMess->getPosition().x - 5 - grFirst->getSize().width, txMess->getPosition().y + (txMess->getSize().height / 2) - (grSecond->getSize().height / 2));
		grSecond->setPosition(txMess->getPosition().x + 5 + txMess->getSize().width, txMess->getPosition().y + (txMess->getSize().height / 2) - (grSecond->getSize().height / 2));

		wd.draw(*border);
		wd.draw(*main);

		txInfo->render(wd);

		btOk->render(wd);

		txMess->render(wd);
		grFirst->render(wd);
		grSecond->render(wd);
	}
}*/
/*
void message::render(RenderWindow& wd) noexcept {
	if (active) {
		wd.draw(*border);
		wd.draw(*main);

		txInfo->render(wd);
		btOk->render(wd);

		txMess->render(wd);
		grFirst->render(wd);
		grSecond->render(wd);
	}
}*/