#include "Group.hpp"

namespace InterfaceComp
{
	CompConteiner& Group::getComponents() 
	{
		return compCont;
	}

	void __fastcall Group::setPosition(int x, int y) 
	{
		setPosition({x, y});
	} 

	void Group::setPosition(const axes_i& xy) 
	{
		pos = xy;
		fl_rect.left = xy.x;
		fl_rect.top = xy.y;

		for (int index = 0; index < compCont.size(); ++index)
		{
			if (index == 0)
			{
				compCont.at(index)->setPosition(xy);
				fl_rect.height = compCont.at(index)->getSize().height;
				fl_rect.width = compCont.at(index)->getSize().width;
			}
			else
			{
				auto& axes = compCont.at(index - 1)->getPosition();		
				compCont.at(index)->setPosition(axes.x, axes.y + compCont.at(index - 1)->getSize().height);

				fl_rect.height += compCont.at(index)->getSize().height;
				fl_rect.width = std::max(compCont.at(index)->getSize().width, fl_rect.width);
			}
		}
	}

	void Group::_render(const RenderWindowPtr& window)
	{
		if (IsVisible())
			compCont.render(window);
	}
}