#pragma once
#include "Base.hpp"
#include "Render.hpp"

namespace InterfaceComp {

	class BaseInerface : public IRender {
		protected:
			axes_i pos;
			FloatRect fl_rect;
		public:
			BaseInerface();
			BaseInerface(int x, int y, const FloatRect& rect);
			BaseInerface(const axes_i& xy, const FloatRect& rect);
			virtual ~BaseInerface() = default;
			virtual const axes_i& getPosition() const;
			virtual void setPosition(const axes_i& xy);
			virtual void __fastcall setPosition(int x, int y);
			virtual const FloatRect& getSize() const;
			virtual void setSize(const sf::FloatRect& rect);
	};

	//����������� ���������
	enum gradient_direction {
		leftOnRight,
		rightOnLeft,
		topOnBottom,
		bottomOnTop
	};

	//������ ������ � ��������
	enum text_size {
		small_t = 24,
		normal = 30,
		medium = 48,
		big = 68
	};

	template<typename arg>
	arg repoz_X(arg X, arg size, arg indent = 0) {
		arg A = 0;
		A = size - X;
		X = X - A;
		return X + indent;
	}

	template<typename arg>
	arg repoz_Y(arg Y, arg size, arg indent = 0) {
		arg A = 0;
		A = size - Y;
		Y = Y - A;
		return Y + indent;
	}

	#define repoz_x(type, X, size, indent) repoz_X <type>(X, size, indent) //��������� ����������� ������� ������ � �������� � ����������� ��� ������������ �������� ��������� ��� ��� X
	#define repoz_y(type, Y, size, indent) repoz_Y <type>(Y, size, indent) //��������� ����������� ������� ������ � �������� � ����������� ��� ������������ �������� ��������� ��� ��� Y

}
//#endif