#include "HLine.h"


HLine::HLine(int h, int v1, int v2) : _h(h) {
	_v1 = std::min(v1, v2);
	_v2 = std::max(v1, v2);
};

void HLine::paint(Canavas& canavas, const Color& color) const {
	canavas.fill(color, vec2(_v1, _h), vec2(_v2, _h));
};