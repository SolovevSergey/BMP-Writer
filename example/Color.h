#pragma once
#include "cstdint"


class Color final{
	int _R, _G, _B;
public:
	Color(int r, int g, int b);

	int getR() const;
	int getG() const;
	int getB() const;
};

static const Color White(255, 255, 255);
static const Color Black(0, 0, 0);
