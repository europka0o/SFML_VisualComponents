#pragma once
#include "InterfBase.hpp"
#include <cassert>

namespace InterfaceComp 
{
	class CompConteiner
	{
		public:
			CompConteiner() = default;
			CompConteiner(const std::initializer_list<BaseInerface*>& components, BaseInerface* ownerComp) : compCont(components), owner(ownerComp)
			{
				for (auto& comp : components)
					draw.add(comp);
			}

			~CompConteiner() = default;

			void add(BaseInerface* comp) 
			{
				assert(owner);

				draw.add(comp);
				compCont.push_back(comp);

				if (compCont.size() == 1)
				{
					comp->setPosition(owner->getPosition());
				}
				else
				{
					auto& axes = compCont.back()->getPosition();
					comp->setPosition(axes.x, axes.y + compCont.back()->getSize().height);
				}
			}

			void add(const std::initializer_list<BaseInerface*>& components)
			{
				for (const auto& comp : components)
				{
					add(comp);
				}
			}

			BaseInerface* at(int index)
			{
				if (index >= 0)
					return compCont[index];
			}

			BaseInerface* operator[] (size_t index)
			{
				if (index >= 0)
					return compCont[index];
			}

			std::vector<BaseInerface*>& vector()
			{
				return compCont;
			}

			size_t size()
			{
				return compCont.size();
			}

		private:
			void render(const RenderWindowPtr& window)
			{
				draw.render(window);
			}

			//Контейнер с комонентами интерфейса
			std::vector<BaseInerface*> compCont;
			DrawManager draw;
			/// Владелец контейнера
			BaseInerface* owner;

			friend class Group;
	};

	class Group : public BaseInerface
	{
		public:
			Group() = default;
			Group(const std::initializer_list<BaseInerface*>& components) : compCont(components, this) 
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