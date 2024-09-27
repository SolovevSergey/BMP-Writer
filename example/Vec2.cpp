#include "Vec2.h"

vec2::vec2() : vec2(0, 0) {};

vec2::vec2(int x, int y) : _x(x), _y(y) {};

vec2 vec2::operator+(const vec2& other) const {
	return vec2(_x + other._x, _y + other._y);
}

vec2 vec2::operator-(const vec2& other) const {
	return vec2(_x + other._x, _y + other._y);
}

int vec2::getX() const { return _x; };

int vec2::getY() const { return _y; };