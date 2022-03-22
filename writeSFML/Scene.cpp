#include "Scene.hpp"

namespace Rep
{
	Scene::Scene()
	{
		window = std::make_shared<sf::RenderWindow>(VideoMode(1920, 1080), "Scene", Style::Default);
	}

	void Scene::build()
	{
		window->clear();

		for (const auto& r : rep)
		{
			r->renderChild(window);
		}

		window->display();
	}

	void Scene::update()
	{
		mousePos = Mouse::getPosition(*window);
		mousePos = Vector2i(window->mapPixelToCoords(mousePos));

		for (const auto& r : rep)
		{
			if (r->isVisible())
			{
				if (r->getSize().contains(mousePos.x, mousePos.y))
				{
					r->setActive(true);
					if (r->onActived)
						r->onActived(r);
				}
				else
				{
					r->setActive(false);
				}

				/*if (r->onClick)
					r->onActived(r);
				if (r->onActived)
					r->onActived(r);*/
			}
		}
	}
}