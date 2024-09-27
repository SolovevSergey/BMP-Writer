#include "Point.h"

Point::Point(int x, int y) : Point(vec2(x, y)) {};
Point::Point(const vec2& pos) : _position(pos) {};

void Point::paint(Canavas& canavas, const Color& color) const {
	canavas.paint(_position, color);
};