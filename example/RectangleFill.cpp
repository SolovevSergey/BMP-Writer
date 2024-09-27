#include "RectangleFill.h"

RectangleFill::RectangleFill(const vec2& start, const vec2& end)
	: RectangleFill(start.getX(), start.getY(), end.getX(), end.getY()) {};

RectangleFill::RectangleFill(int x1, int y1, int x2, int y2) {
	_start = vec2(std::min(x1, x2), std::min(y1, y2));
	_end = vec2(std::max(x1, x2), std::max(y1, y2));
};

void RectangleFill::paint(Canavas& canavas, const Color& color) const {
	canavas.fill(color, _start, _end);
};