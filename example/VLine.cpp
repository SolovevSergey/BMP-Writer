#include "VLine.h"


VLine::VLine(int v, int h1, int h2) : _v(v) {
	_h1 = std::min(h1, h2);
	_h2 = std::max(h1, h2);
};

void VLine::paint(Canavas& canavas, const Color& color) const {
	canavas.fill(color, vec2(_v, _h1), vec2(_v, _h2));
};
