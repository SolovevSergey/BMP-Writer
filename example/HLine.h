#pragma once
#include "Object2D.h"


class HLine final : public Object2D {
	int _h, _v1, _v2;
public:
	HLine(int h, int v1, int v2);

	void paint(Canavas& canavas, const Color& color) const override;
};