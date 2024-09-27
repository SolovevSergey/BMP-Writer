#include "Canavas.h"

Canavas::Canavas(int x1, int y1, int x2, int y2, const Color& back_color) {
	start = vec2(x1, y1);
	end = vec2(x2, y2);
	_bmp.m_width = x2;
	_bmp.m_height = y2;
	size_t buffer_size = _bmp.m_height * _bmp.m_width * 3;
	_bmp.m_buffer = new uint8_t[buffer_size];
	fill(back_color);
};

int Canavas::getMinY() const {
	return start.getY();
}

int Canavas::getMinX() const {
	return start.getX();
}


int Canavas::getMaxY() const {
	return end.getY();
}

int Canavas::getMaxX() const {
	return end.getX();
}

void Canavas::save(const std::string& path) {
	_bmp.save(path);
}

void Canavas::fill(
	const Color& color,
	const vec2& start,
	const vec2& end
)
{
	vec2 _first = cutter_without_canavas(start);
	vec2 _last;
	if (end.getY() == -1 && end.getX() == -1) {
		_last = vec2(getMaxX(), getMaxY());
	}
	else {
		_last = cutter_without_canavas(end);
	}
	for (int x = _first.getX(); x <= _last.getX(); ++x) {
		for (int y = _first.getY(); y <= _last.getY(); ++y) {
			paint(x, y, color);
		}
	}
}

void Canavas::conditionalFill(
	const Color& color,
	std::function<bool(int, int)> alpha,
	const vec2& start,
	const vec2& end
)
{
	vec2 _first = cutter_without_canavas(start);
	vec2 _last;
	if (end.getY() == -1 && end.getX() == -1) {
		_last = vec2(getMaxX(), getMaxY());
	}
	else {
		_last = cutter_without_canavas(end);
	}
	for (int x = _first.getX(); x < _last.getX(); ++x) {
		for (int y = _first.getY(); y < _last.getY(); ++y) {
			if (alpha(x, y)) {
				paint(x, y, color);
			}
		}
	}
}

void Canavas::paint(const vec2& pos, const Color& color) {
	paint(pos.getX(), pos.getY(), color);
}

void Canavas::paint(int x, int y, const Color& color) {
	if (vec2_in_canavas(x, y)) {
		int i = y * COLORS * _bmp.m_width + x * COLORS;
		_bmp.m_buffer[i + 0] = color.getB();
		_bmp.m_buffer[i + 1] = color.getG();
		_bmp.m_buffer[i + 2] = color.getR();
	}
};

vec2 Canavas::cutter_without_canavas(const vec2& point) const {
	int x = std::min(std::max(point.getX(), getMinX()), getMaxX());
	int y = std::min(std::max(point.getY(), getMinY()), getMaxY());
	return vec2(x, y);
};

bool Canavas::vec2_in_canavas(int x, int y) const {
	return y >= getMinY() && y < getMaxY() && x >= getMinX() && x < getMaxX();
};
