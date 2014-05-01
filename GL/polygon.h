#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <GL/glew.h>
#include "vertex.h"

namespace GL {
  class Polygon {
    public:
      void addVertex(Vertex vertex);
      int verticesCount();
      int coordinatesSize();
      int rgbaSize();
      std::vector<GLfloat> getCoordinates();
      std::vector<int> getRGBA();
    private:
      std::vector<Vertex> _vertices;
  };
}

#endif
