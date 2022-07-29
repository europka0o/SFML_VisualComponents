#pragma once
#include <SFML/Graphics.hpp>
#include "Typedef.hpp"
#include <set>

/// ������� ����� ��� ��������� �� ������

class IRender
{
public:
	IRender() : visible(true) {}
	virtual ~IRender() = default;

	bool IsVisible() const;
	void SetVisible(bool vis);

protected:
	virtual void _render(const RenderWindowPtr& window) { return; }
	//virtual void _render(const RegionPtr& view) { return; }

	bool visible;
	friend class DrawManager;
};


/// �������� ���������, ��������������� ������ ��� ������� ��������� � ����������
class DrawManager
{
public:
	DrawManager() = default;
	DrawManager(const std::initializer_list<IRender*>& list) : drawCont(list) {}

	void Add(IRender* rend);
	void Render(const RenderWindowPtr& window);

private:
	using DrawConteiner = std::set<IRender*>;
	DrawConteiner drawCont;
};