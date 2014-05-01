#ifndef POINT_H
#define POINT_H

#include <vector>
#include <GL/glew.h>

namespace GL {
  class Point {
    public:
      Point(GLfloat x = 0.0, GLfloat y = 0.0, GLfloat z = 0.5, GLfloat w = 1.0);
      GLfloat getX();
      GLfloat getY();
      GLfloat getZ();
      GLfloat getW();

      // Gets the pointer to the first GLfloat in the array.
      std::vector<GLfloat> getCoordinates();

    private:
      std::vector<GLfloat> _coordinates;
  };
}

#endif
