#include "game.h"

namespace Game {
  void setup(OpenGL::Program shaderProgram) {
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    static const float data[] = {
      0.25, -0.25, 0.5, 1.0,
      -0.25, -0.25, 0.5, 1.0,
      0.25, 0.25, 0.5, 1.0
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLint posAttrib = glGetAttribLocation(shaderProgram.id(), "position");
    glVertexAttribPointer(posAttrib, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(posAttrib);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  }

  void render(float time) {
    const GLfloat backgroundColor[] = { (float)sin(time) * 0.5f + 0.5f,
                                        (float)cos(time) * 0.5f + 0.5f,
                                        0.0f, 1.0f };

    glClearBufferfv(GL_COLOR, 0, backgroundColor);

    GLfloat trianglePosition[] = { (float)sin(time) * 0.5f,
                                   (float)cos(time) * 0.6f,
                                   0.0f, 0.0f };

    GLfloat triangleColor[] = { (float)cos(time) * 0.7f + 0.5f,
                                (float)sin(time) * 0.7f + 0.5f,
                                0.0f, 1.0f };

    glVertexAttrib4fv(1, triangleColor);
    glVertexAttrib4fv(2, trianglePosition);

    glDrawArrays(GL_PATCHES, 0, 3);
  }
}
