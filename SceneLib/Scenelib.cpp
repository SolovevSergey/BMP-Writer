#include "../example/Scenelib.h"

Scene::Scene(int x1, int y1, int x2, int y2, const Color& brush, const Color& background)
    : _can(Canavas(x1, y1, x2, y2, background)), _col(brush) {};


void Scene::addObject(const Object2D& obj2d) {
    obj2d.paint(_can, _col);
}

void Scene::setColor(const Color& color) {
    _col = color;
};

void Scene::setColor(int r, int g, int b) {
    setColor(Color(r % 256, g % 256, b % 256));
};

void Scene::save(const std::string& file_path) {
    _can.save(file_path);
};