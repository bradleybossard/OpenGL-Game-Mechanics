#include "GL/program.h"
#include "GL/glfw.h"
#include "GL/glew.h"
#include "game.h"

int main(int argc, char* args[])
{
  GL::GLFW glfw("Tessellated Triangle", 1680, 1050);
  GL::GLEW glew;

  // Sets up the variable theProgram with the compiled GLSL program.
  GL::Program shaderProgram;
  shaderProgram.use();

  Game::setup(shaderProgram);

  while(!glfwWindowShouldClose(glfw.getWindow()))
  {
    Game::render(glfwGetTime());

    glfwSwapBuffers(glfw.getWindow());
    glfwPollEvents();
  }

  exit(EXIT_SUCCESS);
}
