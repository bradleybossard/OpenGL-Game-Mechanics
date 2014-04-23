#ifndef GLEW_CLASS
#define GLEW_CLASS

#include <stdio.h>
#include <GL/glew.h>

namespace OpenGL {
  class GLEW {
    public:
      // Constructor sets up GLEW and prints what version of OpenGL is being used.
      GLEW();
  };
}

#endif
