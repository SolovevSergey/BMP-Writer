#include "RectangleVoid.h"

RectangleVoid::RectangleVoid(const vec2& start, const vec2& end)
	: RectangleVoid(start.getX(), start.getY(), end.getX(), end.getY())
{};

RectangleVoid::RectangleVoid(int x1, int y1, int x2, int y2)
	: _x1(std::min(x1, x2)), _x2(std::max(x1, x2)), _y1(std::min(y1, y2)), _y2(std::max(y1, y2))
{};

void RectangleVoid::paint(Canavas& canavas, const Color& color) const {
	canavas.fill(color, vec2(_x1, _y1), vec2(_x1, _y2));
	canavas.fill(color, vec2(_x1, _y1), vec2(_x2, _y1));
	canavas.fill(color, vec2(_x1, _y2), vec2(_x2, _y2));
	canavas.fill(color, vec2(_x2, _y1), vec2(_x2, _y2));
};