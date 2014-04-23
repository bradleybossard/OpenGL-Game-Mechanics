#include "OpenGL/program.h"
#include "OpenGL/glfw.h"
#include "OpenGL/glew.h"
#include "game.h"

int main(int argc, char* args[])
{
  OpenGL::GLFW glfw("Tessellated Triangle", 1680, 1050);
  OpenGL::GLEW glew;

  // Sets up the variable theProgram with the compiled GLSL program.
  OpenGL::Program shaderProgram;
  shaderProgram.use();

  Game::setup(shaderProgram);

  while(!glfwWindowShouldClose(glfw.window))
  {
    Game::render(glfwGetTime());

    glfwSwapBuffers(glfw.window);
    glfwPollEvents();
  }

  exit(EXIT_SUCCESS);
}
