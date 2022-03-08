#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>


using namespace sf;

template<typename type>
struct axes {
	type x, y;
	axes();
	axes(type _x, type _y);
};

//----------------------------------Структура-оси-axes-Начало-------------------------------
template<typename type>
axes<type>::axes() {
	x = 0;
	y = 0;
}

template<typename type>
axes<type>::axes(type _x, type _y) : x(_x), y(_y) {}
//----------------------------------Структура-оси-axes-Конец-------------------------------

using axes_i = axes<int>;
using axes_f = axes<float>;

