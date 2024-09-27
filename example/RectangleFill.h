#pragma once
#include "Object2D.h"

class RectangleFill final : public Object2D {
	vec2 _start, _end;
public:
	RectangleFill(const vec2& start, const vec2& end);
	RectangleFill(int x1, int y1, int x2, int y2);

	void paint(Canavas& canavas, const Color& color) const final;
};