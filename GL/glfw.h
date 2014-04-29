#ifndef GLFW_H
#define GLFW_H

#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "callback.h"

namespace GL {
  class GLFW {
    public:
      GLFW(char* title, int x, int y);
      // Terminates GLFW and deletes the active window.
      ~GLFW();
      GLFWwindow* getWindow();
    private:
      GLFWwindow* _window;

      // Initializes GLFW and sets up it's properties.
      void initGlfw();

      // Creates a window and sets it up as the current context.
      GLFWwindow* createWindow(char* title, int x, int y);
  };
}

#endif
