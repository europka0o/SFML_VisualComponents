#include "Scene.hpp"
#include <SFML/OpenGL.hpp>
//#include <GL/gl.h>

namespace Rep
{
	Scene::Scene()
	{
		window = std::make_shared<sf::RenderWindow>(VideoMode(1920, 1080), "Scene", Style::Default);
		//glMatrixMode(GL_PROJECTION);
	}

	void Scene::build()
	{
		window->clear();

		/*glBegin(GL_QUADS);
		glVertex3f(100, 100, 0);
		glVertex3f(100, 50, 0);
		glVertex3f(100, 50, 30);
		glEnd();*/

		for (const auto& r : rep)
		{
			r->_render(window);
		}

		window->display();
	}

	void Scene::update()
	{
		mousePos = Mouse::getPosition(*window);
		mousePos = Vector2i(window->mapPixelToCoords(mousePos));

		for (const auto& r : rep)
		{
			if (r->IsVisible())
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