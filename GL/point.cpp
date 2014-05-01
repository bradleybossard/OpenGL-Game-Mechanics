#include "point.h"

namespace GL {
  Point::Point(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    _coordinates.push_back(x);
    _coordinates.push_back(y);
    _coordinates.push_back(z);
    _coordinates.push_back(w);
  }

  GLfloat Point::getX() {
    return _coordinates[0];
  }

  GLfloat Point::getY() {
    return _coordinates[1];
  }

  GLfloat Point::getZ() {
    return _coordinates[2];
  }

  GLfloat Point::getW() {
    return _coordinates[3];
  }

  std::vector<GLfloat> Point::getCoordinates() {
    return _coordinates;
  }
}
