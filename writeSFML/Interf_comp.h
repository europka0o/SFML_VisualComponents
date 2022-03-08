#pragma once
/*#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <Windows.h>

#ifndef _INTERFACE_COMPANENTS_ 
#define _INTERFACE_COMPANENTS_

#undef small
using namespace sf;

enum text_size {
	small = 24,   
	normal = 30,  
	medium = 48, 
	big = 68      
};

enum direcrion8 {
	non,
	right = 1,
	left,
	up,
	down,
	upAndRight,
	upAndLeft,
	downAndRight,
	downAndLeft
};

template<typename type>
struct axes {
	type x, y;
	axes();
	axes(type _x, type _y);
};

typedef axes<int> axes_i;
typedef axes<float> axes_f;

template<typename arg>
arg _repoz_x(arg X, arg size, arg indent = 0);

template<typename arg>
arg _repoz_y(arg Y, arg size, arg indent = 0);

#define repoz_x(type, X, size, indent) _repoz_x <type>(X, size, indent) //вычисляет погрешность позиции текста в пикселях и выравнивает его относительно заданных координат для оси X
#define repoz_y(type, Y, size, indent) _repoz_y <type>(Y, size, indent) //вычисляет погрешность позиции текста в пикселях и выравнивает его относительно заданных координат для оси Y

unsigned __int64 wstrToInt(std::wstring input);

int getInputMethod();

class BaseInerface {
	protected:
		axes_i pos;
		FloatRect fl_rect;
	public:
		BaseInerface();
		BaseInerface(int x, int y, const FloatRect &rect);
		BaseInerface(const axes_i &xy, const FloatRect &rect);
		virtual ~BaseInerface();
		bool visible;
		virtual axes_i getPosition();
		virtual void setPosition(const axes_i &xy);
		virtual void __fastcall setPosition(int x, int y);
		virtual FloatRect getSize();
		virtual void render(RenderWindow &wd);
		virtual void render(RenderWindow *wd);
};

class text : public BaseInerface {
	private:
		RectangleShape* bevel; //прямоугольник под текстом 
		Font* font_main;
		std::wstring changeWString(const Event& event);
	public:
		std::wstring exec_console(const std::wstring &command);
		bool shift;
		bool visible_bevel; //видимость прямоугольника под текстом 
		Text* label;
		text(int x, int y, std::wstring txt, Color lbcol, Color bvcol); //координата объекта по оси X, координата объекта по оси Y, текст, цвет текста, цвет прямоугольника
		~text();
		void addWChar(const Event &event, int mode = 6);
		void addWChar(wchar_t symb);
		void addWChar(char32_t symb);
		bool isAction(const Vector2i &pos);
		void setString(std::wstring txt) noexcept; //задаетс текст 
		void setString(sf::String txt) noexcept;
		void setFont(String txt) noexcept; //путь к фону для текста
		void __fastcall setPosition(int x, int y) noexcept override final; //устанавливает позицию объекта по осям X, Y 
		void setPosition(const axes_i& xy) noexcept override final; //устанавливает позицию объекта по осям X, Y 
		void resize(int size) noexcept; //задает размер объекта в пикселях
		void render(RenderWindow& wd) noexcept override final;
		void render(RenderWindow* wd) noexcept override final;
};

class text_chr : public BaseInerface {
	private:
		RectangleShape* bevel; //прямоугольник под текстом 
		Font* font_main;
		Color cl_char;
		Color cl_back;
		float buff_ident;
		int size, line, size_m;
		axes_f real_pos;
		sf::Text* label;
		struct elem_str {
			Color cl_symbl;
			//char32_t symbl;
			int ident_y;
		};
	public:
		bool visible_bevel; //видимость прямоугольника под текстом 
		text_chr(int x, int y, std::wstring txt, Color lbcol, Color bvcol); //координата объекта по оси X, координата объекта по оси Y, текст, цвет текста, цвет прямоугольника
		text_chr(int x, int y, Color lbcol, Color bvcol);
		~text_chr();
		elem_str* caption;
		sf::Vertex point;
		void addWChar(wchar_t symb);
		void add32Char(char32_t symb);
		void setString(std::wstring txt) noexcept; //задаетс текст 
		void setString(sf::String txt) noexcept;
		void setFont(String txt) noexcept; //путь к фону для текста
		void __fastcall setPosition(int x, int y) noexcept override final; //устанавливает позицию объекта по осям X, Y 
		void setPosition(const axes_i& xy) noexcept override final; //устанавливает позицию объекта по осям X, Y 
		void resize(int size) noexcept; //задает размер объекта в пикселях
		void render(RenderWindow& wd) noexcept override final;
		void render(RenderWindow* wd) noexcept override final;
		void newline();
		void clear();
		void malloc_arr(size_t size);
};

class Collision {
	private:
		axes_i pos;
		IntRect rect_collis;
		RectangleShape* main;
	public:
		bool active, visible_deb;
		Collision(const IntRect& rect);
		~Collision();
		void __fastcall setPosition(int x, int y);
		void setPosition(const axes_i& xy);
		axes_i getPosition();
		IntRect getBounds();
		void setBounds(const IntRect& rect);
		void render(RenderWindow& wd);
		void render(RenderWindow* wd);
};

class ObjectStatic {
	protected:
		axes_i pos;
		Sprite* sprt;
		FloatRect react_obj_stat;
	public:
		Collision* rect_collis;
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="i">Указатель на текстуру</param>
		/// <param name="X">Координаты по оси X</param>
		/// <param name="Y">Координаты по оси Y</param>
		/// <returns></returns>
		ObjectStatic(Texture* ptr_texture, float X, float Y);
		~ObjectStatic();
		/// <summary>
		/// Возвращает позицию
		/// </summary>
		/// <returns>Структура axes_i</returns>
		virtual axes_i getPosition();
		/// <summary>
		/// Возвращает данные о хитбоке: ширина, высота, функции проверки пересечения
		/// </summary>
		/// <returns>Структура IntRect</returns>
		virtual FloatRect getSize();
		/// <summary>
		/// Устанавливает новые данные о хитбоксе
		/// </summary>
		/// <param name="bound">Струткура IntRect с новыми параметрами</param>
		virtual void setRect(const IntRect& bound);
		/// <summary>
		/// Устанавливает позицию хитбокса по осям X и Y
		/// </summary>
		/// <param name="x">Ось X</param>
		/// <param name="y">Ось Y</param>
		virtual void __fastcall setPosition(int x, int y);
		/// <summary>
		/// Устанавливает позицию хитбокса по осям X и Y
		/// </summary>
		/// <param name="xy">Структура axes_i с координатами по осям X и Y</param>
		virtual void setPosition(const axes_i& xy);
		virtual void render(RenderWindow& wd);
		virtual void render(RenderWindow* wd);
};

class ObjectAnimated : public ObjectStatic {
	protected:
		float frame;
	public:
		bool end;
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="i">Указатель на текстуру</param>
		/// <param name="X">Координаты по оси X</param>
		/// <param name="Y">Координаты по оси Y</param>
		/// <returns></returns>
		ObjectAnimated(Texture* ptr_texture, float X, float Y);
		~ObjectAnimated();
		/// <summary>
		/// Обновление объекта
		/// </summary>
		/// <param name="time">Время, чем больше значение переменной, тем быстрее происходит обновление</param>
		virtual void __fastcall update(float time);
};

class Meteor : public ObjectAnimated {
	private:
		Sprite* sprt_meteor;
		Vector2f start_point, mouse_point;
		bool reached_point;
		float current_len;
		void isReachedPoint(float time);
	public:
		bool cooldown;
		Meteor(Texture* ptr_texture, Texture* ptr_texture2, float X, float Y);
		~Meteor();
		void __fastcall update(float time) override final;
		void render(RenderWindow& wd) override final;
		void render(RenderWindow* wd) override final;
};

class min_bar : public BaseInerface {
	private:
		int max_br, min_br, curr_br; //Максимальное значение полосы, минимальное значение полосы, текущее значение полосы 
		RectangleShape* main; //Прямоугольник под объектом
		RectangleShape* bevel; //Полоса
	public:
		min_bar(int x, int y, int br_ma, int br_mi, const Color& mcol, const Color& bcol);
		~min_bar();
		void __fastcall setPosition(int x, int y) noexcept override;
		void setPosition(const axes_i& xy) noexcept override;
		void changeBar(int arg) noexcept;
		void render(RenderWindow& wd) noexcept override;
		void render(RenderWindow* wd) noexcept override;
};

#define BASECLASS 0
#define SPERCLASS 1
#define DESTCLASS 2
#define CHARCLASS 3

class BaseCharacter {
	protected:
		axes_f pos;
		IntRect sprite_rect;
		float frame, timer_cooldown;
		bool zeroing;
	public:
		unsigned int id_class;
		BaseCharacter();
		BaseCharacter(const Sprite &ptr_sprite, float x, float y, int _hp, unsigned int id = BASECLASS);
		BaseCharacter(const Sprite &ptr_sprite, const axes_f& xy, int _hp, unsigned int id = BASECLASS);
		virtual ~BaseCharacter();
		bool cooldown, isDead, visible;
		int health;
		virtual axes_f getPosition();
		virtual void __fastcall move(float time, int direct) noexcept;
		virtual void __fastcall setPosition(float x, float y);
		virtual void __fastcall setPosition(const axes_f& xy);
		virtual IntRect getSize();
		virtual void render(RenderWindow& wd, Sprite *ptr_sprite);
		virtual void render(RenderWindow* wd, Sprite *ptr_sprite);
};

class Spearman : public BaseCharacter {
	private:
		int direction, last_direction;
		min_bar* HP;
	public:
		Collision* rect_collis;
		Spearman(const Sprite &ptr_sprite, float X_POS, float Y_POS, int hp, unsigned int id = SPERCLASS);
		virtual ~Spearman();
		void __fastcall setPosition(float x, float y) noexcept override;
		void setPosition(const axes_f& xy) noexcept override;
		void __fastcall move(float time, int direct) noexcept override;
		void __fastcall attack(float time);
		bool isCooldown(float time);
		void render(RenderWindow& wd, Sprite *ptr_sprite) noexcept override;
		void render(RenderWindow* wd, Sprite *ptr_sprite) noexcept override;
};

class DestroerCastle : public BaseCharacter {
	private:
		int direction, last_direction;
		min_bar* HP;
	public:
		Collision* rect_collis;
		DestroerCastle(const Sprite &ptr_sprite, float X_POS, float Y_POS, int hp, unsigned int id = DESTCLASS);
		virtual ~DestroerCastle();
		void __fastcall setPosition(float x, float y) noexcept override;
		void setPosition(const axes_f& xy) noexcept override;
		void __fastcall move(float time, int direct) noexcept override;
		void __fastcall attack(float time);
		bool isCooldown(float time);
		void render(RenderWindow& wd, Sprite *ptr_sprite) noexcept override;
		void render(RenderWindow* wd, Sprite *ptr_sprite) noexcept override;
};

class Character : public BaseCharacter {
	private:
		int direction, last_direction;
		min_bar* HP;
	public:
		Collision* rect_collis;
		Character(const Sprite &ptr_sprite, float X_POS, float Y_POS, int hp, unsigned int id = CHARCLASS);
		virtual ~Character();
		void __fastcall setPosition(float x, float y) noexcept override;
		void setPosition(const axes_f& xy) noexcept override;
		void __fastcall move(float time, int direct = 0) noexcept override;
		void __fastcall attack(float time);
		bool isCooldown(float time);
		void render(RenderWindow& wd, Sprite *ptr_sprite) noexcept override;
		void render(RenderWindow* wd, Sprite *ptr_sprite) noexcept override;
};
*/
/*class Render {
	private:
		static std::vector<void(*)(RenderWindow&, Sprite*)> render_links_chr;
		static std::vector<void(*)(RenderWindow&)> render_links_obj;
	public:
		static void appendRenderLinksChr(void(*ptr_render_f)(RenderWindow&, Sprite*));
		static void appendRenderLinksObj(void(*ptr_render_f)(RenderWindow&));

		static void render();
};*/

//Направление градиента
/*enum gradient_direction {
	leftOnRight,
	rightOnLeft,
	topOnBottom,
	bottomOnTop
};

class gradient : public BaseInerface {
	private:
		std::vector<sf::Color> colors;
		sf::VertexArray *rect;
	public:
			/// <param name="rt">Размер и положение хитбокса</param>
			/// <param name="gd">Направление градиента</param>
			/// <param name="first">Первый цвет градиента</param>
			/// <param name="second">Второй цвет градиента</param>
		gradient(const FloatRect &rt, gradient_direction gd, const Color &first, const Color &second);
		~gradient();
			/// <summary>
			/// Устанавливает позицию объекта по осям X и Y
			/// </summary>
			/// <param name="xy">Структура axes_i с координатами по осям X и Y</param>
		void setPosition(const axes_i &xy) override;
			/// <summary>
			/// Устанавливает позицию объекта по осям X и Y
			/// </summary>
			/// <param name="x">Координаты по оси X</param>
			/// <param name="x">Координаты по оси Y</param>
		void __fastcall setPosition(int x, int y) override;
		void render(RenderWindow &wd) noexcept override;
};

class button : public BaseInerface {
	private:
		Text* txt;
		RectangleShape* main, * active_bvl;
	public:
		bool active;
		button(int x, int y, const Font& font, const wchar_t* text, const Color& maincl, const Color& textcl, const Color& activecl);
		~button();
		void setPosition(const axes_i& xy) override;
		void __fastcall setPosition(int x, int y) override;
		void render(RenderWindow& wd) noexcept override;
		void resize(int size);
		//void freeze(Camer* camera, const axes_i& xy) noexcept; //Замораживает позицию компонента относительно камеры
		//void freeze(Camer* camera, int x, int y) noexcept; //Замораживает позицию компонента относительно камеры
		bool __fastcall isAction(int x, int y);
		bool isAction(const axes_i& xy);
};

class message {
	private:
		axes_i pos;
		RectangleShape* main, * border;
		text* txInfo, * txMess;
		gradient* grFirst, * grSecond;
	public:
		bool active;
		button* btOk;
		message(int x, int y, const Font& font, const wchar_t* txt, const Color& maincl, const Color& bordercl, const Color& textcl);
		~message();
		//void render(RenderWindow& wd, Camer* camera) noexcept;
		void render(RenderWindow& wd) noexcept;
};

#define small char
#endif */