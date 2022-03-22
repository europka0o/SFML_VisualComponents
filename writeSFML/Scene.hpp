#pragma once
#include "InterfBase.hpp"
#include <set>

namespace Rep
{
	class Scene
	{	
		public:
			Scene();
			~Scene() = default;

			void setWindow(const RenderWindowPtr& wd) { window = wd; };
			RenderWindowPtr getWindow() { return window; }

			std::set<InterfaceComp::BaseInerface*>& editRep() { return rep; };

			void build();
			void update();

		private:
			std::set<InterfaceComp::BaseInerface*> rep;
			RenderWindowPtr window;
			Vector2i mousePos;	
	};
}

