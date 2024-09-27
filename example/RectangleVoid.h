#pragma once
#include "Object2D.h"


class RectangleVoid final : public Object2D {
	int _x1, _x2, _y1, _y2;
public:
	RectangleVoid(const vec2& start, const vec2& end);
	RectangleVoid(int x1, int y1, int x2, int y2);

	void paint(Canavas& canavas, const Color& color) const override;
};