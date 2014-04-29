#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <GL/glew.h>
#include "shader.h"

namespace GL {
  class Program {
    public:
      Program();
      ~Program();
      GLuint getHandle();
      GLint status();
      void use();
    private:
      GLuint _handle;
      std::vector<Shader> createShaders();
      void attachShaders(std::vector<Shader> &shaderList);
      void detachShaders(std::vector<Shader> &shaderList);
      void logError();

  };
}

#endif
