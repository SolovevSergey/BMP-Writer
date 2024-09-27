#pragma once
#include "Canavas.h"

class Object2D {
public:
	virtual void paint(Canavas& canavas, const Color& color) const = 0;
};