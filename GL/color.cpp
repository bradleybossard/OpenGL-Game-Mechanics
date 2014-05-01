#include "color.h"

namespace GL {
  Color::Color(int r, int g, int b, int a) {
    _rgba.push_back(r);
    _rgba.push_back(g);
    _rgba.push_back(b);
    _rgba.push_back(a);
  }

  int Color::getR() {
    return _rgba[0];
  }

  int Color::getG() {
    return _rgba[1];
  }

  int Color::getB() {
    return _rgba[2];
  }

  int Color::getA() {
    return _rgba[3];
  }

  std::vector<int> Color::getRGBA() {
    return _rgba;
  }
}
