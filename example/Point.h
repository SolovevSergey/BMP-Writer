#pragma once
#include "Object2D.h"


class Point final : public Object2D {
	vec2 _position;
public:
	Point(int x, int y);
	Point(const vec2& pos);

	void paint(Canavas& canavas, const Color& color) const override;
};
