#include "Group.hpp"

namespace InterfaceComp
{
	int Group::addComp(BaseInerface* compPtr) 
	{

		compCont.push_back(compPtr);
		draw.add()

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
			draw.render(window);
	}

	BaseInerface* Group::At(int index)
	{
		if (index >= 0)
			return compCont[index];
	}
}