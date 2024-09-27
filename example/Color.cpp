#include "Color.h"


Color::Color(int r, int g, int b) : _R(r), _G(g), _B(b) {};

int Color::getR() const { return _R; };
int Color::getG() const { return _G; };
int Color::getB() const { return _B; };
