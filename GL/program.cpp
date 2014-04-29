#include "program.h"

namespace GL {
  // Public

  // Creates a program, creates and attaches shaders to it, links it, logging errors, detaching the shaders after linking the program.
  Program::Program() {
    _handle = glCreateProgram();

    fprintf(stdout, "Constructing Program with ID: %i\n", _handle);

    std::vector<Shader> shaders = createShaders();
    attachShaders(shaders);
    glLinkProgram(_handle);

    if (status() == GL_FALSE) {
      logError();
    }

    detachShaders(shaders);
  }

  Program::~Program() {
    printf("Destructing Program with ID: %i\n", _handle);
    glDeleteProgram(_handle);
  }

  GLuint Program::getHandle() {
    return _handle;
  }

  GLint Program::status() {
    GLint status;
    glGetProgramiv(_handle, GL_LINK_STATUS, &status);

    return status;
  }

  // Use this program as the current program.
  void Program::use() {
    glUseProgram(_handle);
  }
  // END Public

  // Private

  // Gather shaders to compile them.
  // TODO: Find a better way to do this.
  std::vector<Shader> Program::createShaders() {
    std::vector<Shader> shaders;

    shaders.push_back(Shader(GL_VERTEX_SHADER, "Shaders/vertex.shader"));
    shaders.push_back(Shader(GL_FRAGMENT_SHADER, "Shaders/fragment.shader"));
    shaders.push_back(Shader(GL_TESS_CONTROL_SHADER, "Shaders/tesselation_control.shader"));
    shaders.push_back(Shader(GL_TESS_EVALUATION_SHADER, "Shaders/tesselation_evaluation.shader"));

    return shaders;
  }

  void Program::attachShaders(std::vector<Shader> &shaders) {
    for (size_t iLoop = 0; iLoop < shaders.size(); iLoop++) {
      shaders[iLoop].attachTo(_handle);
    }
  }

  // TODO: Use glGetAttachedShaders instead of passing it in.
  // https://www.khronos.org/opengles/sdk/docs/man/xhtml/glGetAttachedShaders.xml
  void Program::detachShaders(std::vector<Shader> &shaders) {
    for (size_t iLoop = 0; iLoop < shaders.size(); iLoop++) {
      shaders[iLoop].detachFrom(_handle);
    }
  }

  void Program::logError() {
    GLint infoLogLength;
    glGetProgramiv(_handle, GL_INFO_LOG_LENGTH, &infoLogLength);

    GLchar *strInfoLog = new GLchar[infoLogLength + 1];
    glGetProgramInfoLog(_handle, infoLogLength, NULL, strInfoLog);
    fprintf(stderr, "Program linker failure: %s\n", strInfoLog);
    delete[] strInfoLog;
  }
  // END Private
}
