#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "callback.h"

namespace OpenGL {
  class GLFW {
    public:
      GLFW(char* title, int x, int y);
      // Terminates GLFW and deletes the active window.
      ~GLFW();

      GLFWwindow* window;
    private:
      // Initializes GLFW and sets up it's properties.
      void initGlfw();

      // Creates a window and sets it up as the current context.
      GLFWwindow* createWindow(char* title, int x, int y);
  };
}
