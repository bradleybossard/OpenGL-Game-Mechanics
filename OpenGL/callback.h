#include <stdio.h>
#include <GLFW/glfw3.h>

namespace Callback {
  void GlfwError(int error, const char* description);
  void GlfwKey(GLFWwindow* window, int key, int scancode, int action, int mods);
}
