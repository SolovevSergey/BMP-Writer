#include "..\BMPLib\bitmaplib.hpp"
#include "Scenelib.h"

#include <fstream>
#include <sstream>
#include <iostream>
using Rectangle = RectangleFill;

int main(int argc, char* argv[]) {
    const std::string res_path = ".\\res.bmp";
    const std::string src_path = ".\\src.txt";

    std::ifstream file(src_path);
    if (!file.is_open()) {
        std::cerr << "Error file not opened: '" << src_path << "'\n";
        exit(100);
    }
    int x1, y1, x2, y2;
    unsigned int r;

    file >> x1 >> y1 >> x2 >> y2;   
    Scene scene(x1, y1, x2, y2);

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        ss >> type;
        if (type == "point") {
            ss >> x1 >> y1;
            scene.addObject(Point(x1, y1));
        }
        else if (type == "rect") {
            ss >> x1 >> y1 >> x2 >> y2;
            scene.addObject(Rectangle(x1, y1, x2, y2));
        }
        else if (type == "rect_v") {
            ss >> x1 >> y1 >> x2 >> y2;
            scene.addObject(RectangleVoid(x1, y1, x2, y2));
        }
        else if (type == "rect_f") {
            ss >> x1 >> y1 >> x2 >> y2;
            scene.addObject(RectangleFill(x1, y1, x2, y2));
        }
        else if (type == "hline") {
            ss >> x1 >> x2 >> y1;
            scene.addObject(HLine(y1, x1, x2));
        }
        else if (type == "vline") {
            ss >> y1 >> y2 >> x1;
            scene.addObject(VLine(x1, y1, y2));
        }
        else if (type == "circle") {
            ss >> x1 >> y1 >> r;
            scene.addObject(CircleFill(x1, y1, r));
        }
        else if (type == "square") {
            ss >> x1 >> y1 >> r;
            scene.addObject(Rectangle(x1, y1, x1 + r, y1 + r));
        }
        else if (type == "square_v") {
            ss >> x1 >> y1 >> r;
            scene.addObject(RectangleVoid(x1, y1, x1 + r, y1 + r));
        }
        else if (type == "square_f") {
            ss >> x1 >> y1 >> r;
            scene.addObject(RectangleFill(x1, y1, x1 + r, y1 + r));
        }
        else if (type == "set_color") {
            int r, g, b;
            ss >> r >> g >> b;
            scene.setColor(r, g, b);
        }
    }
    scene.save(res_path);
    return 0;
}