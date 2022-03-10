#pragma once
#include "InterfBase.hpp"

namespace InterfaceComp 
{
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

			void add(BaseInerface* comp) 
			{
				draw.add(comp);
				compCont.push_back(comp);

				/*auto& axis = 

					for ()
					{
					}*/
			}

			void add(const std::initializer_list<BaseInerface*>& components)
			{
				for (const auto& comp : components)
				{
					draw.add(comp);
					compCont.push_back(comp);
				}
			}

			BaseInerface* At(int index)
			{
				if (index >= 0)
					return compCont[index];
			}

			BaseInerface* operator[] (size_t index)
			{
				if (index >= 0)
					return compCont[index];
			}

		private:
			void render(const RenderWindowPtr& window)
			{
				draw.render(window);
			}

			std::vector<BaseInerface*> compCont;
			//Контейнер с комонентами интерфейса
			DrawManager draw;

			friend class Group;
	};

	class Group : public BaseInerface
	{
		public:
			Group() = default;
			Group(const std::initializer_list<BaseInerface*>& components) : compCont(components) 
			{
			}

			~Group() = default;

			void __fastcall setPosition(int x, int y) override; //Устанавливает позицию объекта по осям X, Y
			void setPosition(const axes_i& xy) override; //Устанавливает позицию объекта по осям X, Y 
			CompConteiner& getComponents();
			void renderChild(const RenderWindowPtr& window) override;

			BaseInerface* operator[] (size_t index)
			{
				if (index >= 0)
					return compCont[index];
			}

		private:
			CompConteiner compCont;
	};
}