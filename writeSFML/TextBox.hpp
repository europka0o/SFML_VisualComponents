#pragma once
#include "InterfBase.hpp"

namespace InterfaceComp {

	class TextBox : public BaseInerface {
		private:
			RectangleShape* bevel; //������������� ��� ������� 
		public:
			bool visible_bevel; //��������� �������������� ��� ������� 
			Text* label;
			TextBox(const Font& font, int x = 0, int y = 0, const wchar_t* txt = L"NON:", const Color& lbcol = Color::White, const Color& bvcol = Color::Black);
			~TextBox();
			void setString(const wchar_t* txt); //������ ����� 
			void setFont(const Font& font); //���� � ���� ��� ������
			void __fastcall setPosition(int x, int y) override; //������������� ������� ������� �� ���� X, Y
			void setPosition(const axes_i& xy) override; //������������� ������� ������� �� ���� X, Y 
			void resize(int size = InterfaceComp::text_size::normal); //������ ������ ������� � ��������
		protected:
			void _render(const RenderWindowPtr& window) override;
	};

}