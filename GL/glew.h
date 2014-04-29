#ifndef GLEW_H
#define GLEW_H

#include <stdio.h>
#include <GL/glew.h>

namespace GL {
  class GLEW {
    public:
      // Constructor sets up GLEW and prints what version of OpenGL is being used.
      GLEW();
  };
}

#endif
