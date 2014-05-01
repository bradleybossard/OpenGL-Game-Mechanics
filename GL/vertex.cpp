#include "vertex.h"

namespace GL {
  Vertex::Vertex(Point point, Color color) {
    setPoint(point);
    setColor(color);
  }

  std::vector<GLfloat> Vertex::getCoordinates() {
    return _point.getCoordinates();
  }

  void Vertex::setPoint(Point point) {
    _point = point;
  }

  std::vector<int> Vertex::getRGBA() {
    return _color.getRGBA();
  }

  void Vertex::setColor(Color color) {
    _color = color;
  }
}
