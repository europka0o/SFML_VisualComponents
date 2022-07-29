#include "Render.hpp"	

bool IRender::IsVisible() const 
{
	return visible;
}

void IRender::SetVisible(bool vis) 
{
	visible = vis;
}

void DrawManager::Add(IRender* rend)
{
	drawCont.insert(rend);	
}

void DrawManager::Render(const RenderWindowPtr& window)
{
	for (auto& child : drawCont)
		if(child->IsVisible())
			child->_render(window);
}