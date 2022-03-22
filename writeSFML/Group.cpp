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

		for (int index = 0; index < compCont.size(); ++index)
		{
			if (index == 0)
			{
				compCont.at(index)->setPosition(xy);
			}
			else
			{
				auto& axes = compCont.at(index - 1)->getPosition();		
				compCont.at(index)->setPosition(axes.x, axes.y + compCont.at(index)->getSize().height);
			}
		}
	}

	void Group::renderChild(const RenderWindowPtr& window) 
	{
		if (isVisible())
			compCont.render(window);
	}
}