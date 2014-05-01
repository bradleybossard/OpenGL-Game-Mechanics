#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <GL/glew.h>
#include "point.h"
#include "color.h"

namespace GL {
  class Vertex {
    public:
      Vertex(Point point, Color color = Color());
      std::vector<GLfloat> getCoordinates();
      void setPoint(Point point);
      std::vector<int> getRGBA();
      void setColor(Color color);

    private:
      Point _point;
      Color _color;
  };
}

#endif
