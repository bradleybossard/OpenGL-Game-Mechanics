#include <vector>
#include <GL/glew.h>
#include "shader.h"

namespace OpenGL {
  class Program {
    public:
      Program();
      ~Program();
      GLuint id();
      GLint status();
      void use();
    private:
      GLuint programId;
      std::vector<Shader> createShaders();
      void attachShaders(std::vector<Shader> &shaderList);
      void detachShaders(std::vector<Shader> &shaderList);
      void logError();

  };
}
