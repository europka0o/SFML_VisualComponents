#pragma once
#include "InterfBase.hpp"

namespace InterfaceComp {

	class TextBox : public BaseInerface {
		private:
			RectangleShape* bevel; //Прямоугольник под текстом 
		public:
			bool visible_bevel; //Видимость прямоугольника под текстом 
			Text* label;
			TextBox(const Font& font, int x = 0, int y = 0, const wchar_t* txt = L"NON:", const Color& lbcol = Color::White, const Color& bvcol = Color::Black);
			~TextBox();
			void setString(const wchar_t* txt); //Задает текст 
			void setFont(const Font& font); //Путь к фону для текста
			void __fastcall setPosition(int x, int y) override; //Устанавливает позицию объекта по осям X, Y
			void setPosition(const axes_i& xy) override; //Устанавливает позицию объекта по осям X, Y 
			void resize(int size = InterfaceComp::text_size::normal); //Задает размер объекта в пикселях
		protected:
			void _render(const RenderWindowPtr& window) override;
	};

}