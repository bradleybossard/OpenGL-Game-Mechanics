#ifndef SHADER_CLASS
#define SHADER_CLASS

#include <GL/glew.h>
#include "../Util.h"

namespace OpenGL {
  class Shader {
    public:
      Shader(GLenum shaderType, char* shaderLocation);
      GLuint id();
      GLint status();
      void attachTo(GLuint programId);
      void detachFrom(GLuint programId);
    private:
      GLuint shaderId;
      void logError(char* location);
  };
}

#endif
