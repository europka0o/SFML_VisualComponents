#include "InterfBase.hpp"

//--------------------------------База-Интерфейса-BaseInterface-Начало------------------------------------------

namespace InterfaceComp
{

	BaseInerface::BaseInerface() :
		pos(axes_i(0, 0)),
		fl_rect(Vector2f(0, 0), Vector2f(0, 0))
	{
	}

	BaseInerface::BaseInerface(int x, int y, const FloatRect& rect) :
		pos(axes_i(x, y)),
		fl_rect(rect)
	{
	}

	BaseInerface::BaseInerface(const axes_i& xy, const FloatRect& rect) :
		pos(xy),
		fl_rect(rect)
	{
	}

	const axes_i& BaseInerface::getPosition() const {
		return pos;
	}

	void BaseInerface::setPosition(const axes_i& xy) {
		pos = xy;
	}

	void BaseInerface::setPosition(int x, int y) {
		pos.x = x;
		pos.y = y;
	}

	const FloatRect& BaseInerface::getSize() const {
		return fl_rect;
	}

	void BaseInerface::setSize(const sf::FloatRect& rect) {
		fl_rect = rect;
	}
}
//--------------------------------База-Интерфейса-BaseInterface-Конец------------------------------------------