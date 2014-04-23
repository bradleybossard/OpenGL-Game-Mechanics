#include "glfw.h"

namespace OpenGL {
  // Public
  GLFW::GLFW(char* title, int x, int y) {
    initGlfw();
    window = createWindow(title, x, y);
  }

  GLFW::~GLFW() {
    printf("Destructing GLFW window\n");
    glfwDestroyWindow(window);
    glfwTerminate();
  }
  // END Public

  // Private

  // Initializes GLFW, sets the error callback, sets up GLFW properties.
  void GLFW::initGlfw() {
    glfwSetErrorCallback(Callback::GlfwError);

    if (!glfwInit()) {
      fprintf(stderr, "Failed initialize GLFW.");
      exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  }

  // Creates a window, alerting and terminating on failure, sets the window as the current context, and sets up the keyboard callbacks for the window.
  GLFWwindow* GLFW::createWindow(char* title, int x, int y) {
    printf("Creating a GLFW window with title: %s, of size: %ix%i \n", title, x, y);
    GLFWwindow* window = glfwCreateWindow(x, y, title, NULL, NULL);

    if(!window) {
      fprintf(stderr, "Failed to create GLFW window.");
      glfwTerminate();
      exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, Callback::GlfwKey);

    return window;
  }
}
