#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include "../Util.h"

namespace GL {
  class Shader {
    public:
      Shader(GLenum shaderType, char* shaderLocation);
      GLuint getHandle();
      GLint status();
      void attachTo(GLuint programId);
      void detachFrom(GLuint programId);
    private:
      GLuint _handle;
      void logError(char* location);
  };
}

#endif
