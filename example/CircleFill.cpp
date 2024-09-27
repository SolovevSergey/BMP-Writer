#include "CircleFill.h"


bool CircleFill::in_circle(int x, int y) const {
	int dx = x - _cx;
	int dy = y - _cy;
	return (dx * dx + dy * dy) < _r * _r;
};

CircleFill::CircleFill(int x, int y, int r) : _cx(x), _cy(y), _r(r) {};

void CircleFill::paint(Canavas& canavas, const Color& color) const {
	Canavas::condition_alpha cond = [this](int x, int y) {return this->in_circle(x, y); };
	canavas.conditionalFill(color, cond, vec2(_cx - _r, _cy - _r), vec2(_cx + _r, _cy + _r));
};