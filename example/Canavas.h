#pragma once
#include "..\BMPLib\bitmaplib.hpp"
#include "Color.h"
#include "Vec2.h"
#include <functional>


class Canavas final{
	vec2 start, end;
	static const unsigned int COLORS = 3;
	Bitmap _bmp;
public:
	using condition_alpha = std::function<bool(int, int)>;
	using condition_color = std::function<Color(int, int)>;

	Canavas(int v1, int h1, int v2, int h2, const Color& back_color = Color(0, 0, 0));
	Canavas(const Canavas& other) = default;
	~Canavas() = default;


	int getMinY() const;
	int getMinX() const;
	int getMaxY() const;
	int getMaxX() const;

	void save(const std::string& path);

	void fill(
		const Color& color,
		const vec2& start = vec2(),
		const vec2& end = vec2(-1, -1));

	void conditionalFill(
		const Color& color,
		std::function<bool(int, int)> alpha,
		const vec2& start = vec2(),
		const vec2& end = vec2(-1, -1));

	void paint(const vec2& pos, const Color& color);

	void paint(int w, int h, const Color& color);
private:
	vec2 cutter_without_canavas(const vec2& point) const;

	bool vec2_in_canavas(int w, int h) const;
};
