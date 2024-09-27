#pragma once
#include "Object2D.h"

class VLine final : public Object2D {
	int _v, _h1, _h2;
public:
	VLine(int v, int h1, int h2);

	void paint(Canavas& canavas, const Color& color) const override;
};