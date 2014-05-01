#include "game.h"
#include "GL/polygon.h"

namespace Game {
  void setup(GL::Program shaderProgram) {
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    static const float data[] = {
      0.25, -0.25, 0.5, 1.0,
      -0.25, -0.25, 0.5, 1.0,
      0.25, 0.25, 0.5, 1.0
    };

    GL::Point p1 = GL::Point(0.25, -0.25);
    GL::Point p2 = GL::Point(-0.25, -0.25);
    GL::Point p3 = GL::Point(0.25, 0.25);
    GL::Vertex v1 = GL::Vertex(p1);
    GL::Vertex v2 = GL::Vertex(p2);
    GL::Vertex v3 = GL::Vertex(p3);
    GL::Polygon poly = GL::Polygon();
    poly.addVertex(v1);
    poly.addVertex(v2);
    poly.addVertex(v3);

    for (size_t i = 0; i < poly.getCoordinates().size(); i++) {
      printf("%f, ", poly.getCoordinates()[i]);
    }

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, poly.coordinatesSize(), &poly.getCoordinates().front(), GL_STATIC_DRAW);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLint posAttrib = glGetAttribLocation(shaderProgram.getHandle(), "position");
    glVertexAttribPointer(posAttrib, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(posAttrib);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  }

  void render(float time) {
    const GLfloat backgroundColor[] = { (float)sin(time) * 0.5f + 0.5f,
                                        (float)cos(time) * 0.5f + 0.5f,
                                        0.0f, 1.0f };

    glClearBufferfv(GL_COLOR, 0, backgroundColor);

    GLfloat offset[] = { (float)sin(time) * 0.5f,
                                   (float)cos(time) * 0.6f,
                                   0.0f, 0.0f };

    GLfloat triangleColor[] = { (float)cos(time) * 0.7f + 0.5f,
                                (float)sin(time) * 0.7f + 0.5f,
                                0.0f, 1.0f };

    glVertexAttrib4fv(1, triangleColor);
    glVertexAttrib4fv(2, offset);

    glDrawArrays(GL_PATCHES, 0, 3);
  }
}
