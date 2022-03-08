#pragma once
#include <SFML/Graphics.hpp>
#include "Typedef.hpp"

/// Базовый класс для отрисовки на экране

class IRender
{
public:
	IRender() : visible(true) {}
	virtual ~IRender() = default;

	bool isVisible() const;
	void SetVisible(bool vis);

protected:
	virtual void renderChild(const RenderWindowPtr& window) { return; }

	bool visible;
	friend class DrawManager;
};


/// Менеджер рисования, последовательно рисует все объекты хранящися в контейнире
class DrawManager
{
public:
	DrawManager() = default;
	DrawManager(const std::initializer_list<IRender*>& list) : drawCont(list) {}

	void add(IRender* rend);
	void render(const RenderWindowPtr& window);

private:
	using DrawConteiner = std::vector<IRender*>;
	DrawConteiner drawCont;
};