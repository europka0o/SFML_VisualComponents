#include "Group.hpp"

namespace InterfaceComp
{
	CompConteiner& Group::getComponents() 
	{
		return compCont;
	}

	void __fastcall Group::setPosition(int x, int y) 
	{
	
	} 

	void Group::setPosition(const axes_i& xy) 
	{
	
	}

	void Group::renderChild(const RenderWindowPtr& window) 
	{
		if (isVisible())
			compCont.render(window);
	}
}