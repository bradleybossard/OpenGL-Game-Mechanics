#include "polygon.h"

namespace GL {
  void Polygon::addVertex(Vertex vertex) {
    _vertices.push_back(vertex);
  }

  int Polygon::verticesCount() {
    return _vertices.size();
  }

  int Polygon::coordinatesSize() {
    int length = 0;

    for (size_t i = 0; i < _vertices.size(); i++) {
      length += _vertices[i].getCoordinates().size();
    }

    return length * sizeof(GLfloat);
  }

  int Polygon::rgbaSize() {
    int length = 0;

    for (size_t i = 0; i < _vertices.size(); i++) {
      length += _vertices[i].getRGBA().size();
    }

    return length * sizeof(GLfloat);
  }

  std::vector<GLfloat> Polygon::getCoordinates() {
    std::vector<GLfloat> coordinates;
    int size = 0;

    for (size_t i = 0; i < _vertices.size(); i++) {
      size += _vertices[i].getCoordinates().size();
    }

    coordinates.reserve(size);

    for (size_t i = 0; i < _vertices.size(); i++) {
      coordinates.insert(coordinates.end(), _vertices[i].getCoordinates().begin(), _vertices[i].getCoordinates().end());
    }

    return coordinates;
  }

  std::vector<int> Polygon::getRGBA() {
    std::vector<int> rgba;
    int size = 0;

    for (size_t i = 0; i < _vertices.size(); i++) {
      size += _vertices[i].getRGBA().size();
    }

    rgba.reserve(size);

    for (size_t i = 0; i < _vertices.size(); i++) {
      rgba.insert(rgba.end(), _vertices[i].getRGBA().begin(), _vertices[i].getRGBA().end());
    }

    return rgba;
  }

}
