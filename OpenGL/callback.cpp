#include "callback.h"

namespace Callback {
  void GlfwError(int error, const char* description) {
    fputs(description, stderr);
  }

  // Esc button causes the window to close.
  void GlfwKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(window, GL_TRUE);
    }
  }
}
