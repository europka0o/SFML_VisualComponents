#pragma once
#include "InterfBase.hpp"

namespace InterfaceComp 
{
	class Group : public BaseInerface
	{
		public:
			Group() = default;
			Group(const std::initializer_list<BaseInerface*>& components) : compCont(components) 
			{
				for (auto& comp : components)
					draw.add(comp);
			}

			~Group() = default;

			int addComp(BaseInerface* compPtr);		
			void __fastcall setPosition(int x, int y) override; //Устанавливает позицию объекта по осям X, Y
			void setPosition(const axes_i& xy) override; //Устанавливает позицию объекта по осям X, Y 
			void renderChild(const RenderWindowPtr& window) override;
			BaseInerface* At(int index);
		private:

			class CompConteiner 
			{
				public:
					CompConteiner() = default;
					CompConteiner(const std::initializer_list<BaseInerface*>& components) : compCont(components)
					{
						for (auto& comp : components)
							draw.add(comp);
					}

					~CompConteiner() = default;

					void add() {}

					void render(const RenderWindowPtr& window)
					{
						draw.render(window);
					}

				private:
					std::vector<BaseInerface*> compCont;
					//Контейнер с комонентами интерфейса
					DrawManager draw;
			};



	};
}