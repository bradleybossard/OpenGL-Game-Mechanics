#include "glew.h"

namespace OpenGL {
  // Public
  GLEW::GLEW() {
    glewExperimental = GL_TRUE;
    glewInit();
    printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));
  }
  // END Public
}
