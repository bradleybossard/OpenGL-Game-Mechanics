#include "shader.h"

namespace OpenGL {
  // Public
  Shader::Shader(GLenum type, char* location) {
    shaderId = glCreateShader(type);

    GLchar* src = Util::fileToBuffer(location);
    glShaderSource(shaderId, 1, (const GLchar**)&src, NULL);

    printf("Compiling Shader: %s ID: %i\n", location, shaderId);
    glCompileShader(shaderId);

    if (status() == GL_FALSE) {
      logError(location);
    }
  }

  GLuint Shader::id() {
    return shaderId;
  }

  GLint Shader::status() {
    GLint status;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);

    return status;
  }

  void Shader::attachTo(GLuint programId) {
    printf("Attaching shader: %i to program: %i\n", shaderId, programId);
    glAttachShader(programId, shaderId);
  }

  void Shader::detachFrom(GLuint programId) {
    printf("Detaching shader: %i from program: %i\n", shaderId, programId);
    glDetachShader(programId, shaderId);
    printf("Deleting shader: %i\n", shaderId);
    glDeleteShader(shaderId);
  }
  // END Public

  // Private
  void Shader::logError(char* location) {
    GLint infoLogLength;
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

    GLchar *strInfoLog = new GLchar[infoLogLength + 1];
    glGetShaderInfoLog(shaderId, infoLogLength, NULL, strInfoLog);

    fprintf(stderr, "Shader Compile failure in %s:\n%s\n", location, strInfoLog);
    delete[] strInfoLog;
  }
  // END Private
}
