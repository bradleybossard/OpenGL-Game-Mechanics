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

    for (size_t i = 0; i < _vertices.size(); i++) {
      for (size_t j = 0; j < _vertices[i].getCoordinates().size(); j++) {
        coordinates.push_back(_vertices[i].getCoordinates()[j]);
      }
    }

    return coordinates;
  }

  std::vector<int> Polygon::getRGBA() {
    std::vector<int> rgba;

    for (size_t i = 0; i < _vertices.size(); i++) {
      for (size_t j = 0; j < _vertices[i].getRGBA().size(); j++) {
        rgba.push_back(_vertices[i].getRGBA()[j]);
      }
    }

    return rgba;
  }

}
