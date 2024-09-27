#pragma once

class vec2 {
	int _x, _y;
public:
	vec2();
	vec2(int w, int h);

	vec2 operator+(const vec2& other) const;
	vec2 operator-(const vec2& other) const;

	int getX() const;
	int getY() const;
};
