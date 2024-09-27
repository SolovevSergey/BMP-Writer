#pragma once

#include "Canavas.h"
#include "Point.h"
#include "RectangleFill.h"
#include "RectangleVoid.h"
#include "HLine.h"
#include "VLine.h"
#include "CircleFill.h"

#include <vector>

class Scene {
    Canavas _can;
    Color _col;
public:
    using Rectangle = RectangleFill; 
    Scene(int sw, int sh, int ew, int eh, const Color& brush = Color(255, 255, 255), const Color& background = Color(0, 0, 0));
    Scene(const Scene& other) = default;

    void setColor(const Color& color);
    void setColor(int r, int g, int b);

    void save(const std::string& file_path);

    void addObject(const Object2D& obj2d);
};