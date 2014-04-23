#include "program.h"

namespace OpenGL {
  // Public

  // Creates a program, creates and attaches shaders to it, links it, logging errors, detaching the shaders after linking the program.
  Program::Program() {
    programId = glCreateProgram();

    fprintf(stdout, "Constructing Program with ID: %i\n", programId);

    std::vector<Shader> shaders = createShaders();
    attachShaders(shaders);
    glLinkProgram(programId);

    if (status() == GL_FALSE) {
      logError();
    }

    detachShaders(shaders);
  }

  Program::~Program() {
    printf("Destructing Program with ID: %i\n", programId);
    glDeleteProgram(programId);
  }

  GLuint Program::id() {
    return programId;
  }

  GLint Program::status() {
    GLint status;
    glGetProgramiv(programId, GL_LINK_STATUS, &status);

    return status;
  }

  // Use this program as the current program.
  void Program::use() {
    glUseProgram(programId);
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
      shaders[iLoop].attachTo(programId);
    }
  }

  // TODO: Use glGetAttachedShaders instead of passing it in.
  // https://www.khronos.org/opengles/sdk/docs/man/xhtml/glGetAttachedShaders.xml
  void Program::detachShaders(std::vector<Shader> &shaders) {
    for (size_t iLoop = 0; iLoop < shaders.size(); iLoop++) {
      shaders[iLoop].detachFrom(programId);
    }
  }

  void Program::logError() {
    GLint infoLogLength;
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);

    GLchar *strInfoLog = new GLchar[infoLogLength + 1];
    glGetProgramInfoLog(programId, infoLogLength, NULL, strInfoLog);
    fprintf(stderr, "Program linker failure: %s\n", strInfoLog);
    delete[] strInfoLog;
  }
  // END Private
}
