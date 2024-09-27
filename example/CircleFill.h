#pragma once
#include "Object2D.h"


class CircleFill final : public Object2D {
	int _cx, _cy;
	unsigned int _r;
public:
	CircleFill(int x, int y, int r);

	void paint(Canavas& canavas, const Color& color) const override;

private:
	bool in_circle(int x, int y) const;
};