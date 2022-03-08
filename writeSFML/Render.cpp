#include "Render.hpp"	

bool IRender::isVisible() const 
{
	return visible;
}

void IRender::SetVisible(bool vis) 
{
	visible = vis;
}

void DrawManager::add(IRender* rend)
{
	drawCont.push_back(rend);	
}

void DrawManager::render(const RenderWindowPtr& window)
{
	for (auto& child : drawCont)
		if(child->isVisible())
			child->renderChild(window);
}