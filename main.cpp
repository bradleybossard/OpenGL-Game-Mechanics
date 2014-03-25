#include "includes.h"

GLuint shaderProgram;

void errorCallback(int error, const char* description)
{
  fputs(description, stderr);
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

char* fileToBuffer(char *file)
{
  FILE *fptr;
  long length;
  char *buf;

  fptr = fopen(file, "rb"); /* Open file for reading */
  if (!fptr) /* Return NULL on failure */
      return NULL;
  fseek(fptr, 0, SEEK_END); /* Seek to the end of the file */
  length = ftell(fptr); /* Find out how many bytes into the file we are */
  buf = (char*)malloc(length+1); /* Allocate a buffer for the entire length of the file and a null terminator */
  fseek(fptr, 0, SEEK_SET); /* Go back to the beginning of the file */
  fread(buf, length, 1, fptr); /* Read the contents of the file in to the buffer */
  fclose(fptr); /* Close the file */
  buf[length] = 0; /* Null terminator */

  return buf; /* Return the buffer */
}

GLuint createProgram(const std::vector<GLuint> &shaderList)
{
  GLuint program = glCreateProgram();

  for(size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
  {
    glAttachShader(program, shaderList[iLoop]);
  }

  glLinkProgram(program);

  GLint status;
  glGetProgramiv (program, GL_LINK_STATUS, &status);
  if (status == GL_FALSE)
  {
      GLint infoLogLength;
      glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

      GLchar *strInfoLog = new GLchar[infoLogLength + 1];
      glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
      fprintf(stderr, "Linker failure: %s\n", strInfoLog);
      delete[] strInfoLog;
  }

  for(size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
  {
    glDetachShader(program, shaderList[iLoop]);
  }

  return program;
}

GLuint createShader(GLenum shaderType, char* shaderFile)
{
  GLuint shader = glCreateShader(shaderType);
  GLchar* shaderSrc = fileToBuffer(shaderFile);
  glShaderSource(shader, 1, (const GLchar**)&shaderSrc, NULL);
  glCompileShader(shader);

  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if (status == GL_FALSE)
  {
    GLint infoLogLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

    GLchar *strInfoLog = new GLchar[infoLogLength + 1];
    glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

    const char *strShaderType = NULL;
    switch(shaderType)
    {
    case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
    case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
    case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
    }
    fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
    delete[] strInfoLog;
  }

  return shader;
}

void initProgram()
{
  std::vector<GLuint> shaderList;

  shaderList.push_back(createShader(GL_VERTEX_SHADER, "vertex.shader"));
  shaderList.push_back(createShader(GL_FRAGMENT_SHADER, "fragment.shader"));

  shaderProgram = createProgram(shaderList);

  std::for_each(shaderList.begin(), shaderList.end(), glDeleteShader);
}

int main( int argc, char* args[] )
{
  GLFWwindow* window;
  glfwSetErrorCallback(errorCallback);

  if (!glfwInit())
  {
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  window = glfwCreateWindow(1680, 1050, "OpenGL", NULL, NULL);
  if(!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, keyCallback);

  glewExperimental = GL_TRUE;
  glewInit();
  printf("OpenGL version supported by this platform (%s): \n", glGetString(GL_VERSION));

  glClearColor( 0.f, 0.f, 0.f, 1.f );

  // Sets up the variable theProgram with the compiled GLSL program.
  initProgram();
  glUseProgram(shaderProgram);

  float vertices[] = {
       0.0f,  0.5f, // Vertex 1 (X, Y)
       0.5f, -0.5f, // Vertex 2 (X, Y)
      -0.5f, -0.5f  // Vertex 3 (X, Y)
  };

  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);

  GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(posAttrib);

  GLint uniColor = glGetUniformLocation(shaderProgram, "triangleColor");

  while(!glfwWindowShouldClose(window))
  {
    float time = (float)clock() / (float)CLOCKS_PER_SEC;
    printf("Time: %f, R: %f\n", time, (sin(time * 4.0f) + 1.0f) / 2.0f);
    glUniform3f(uniColor, (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);
    printf("GL Error: %s\n", gluErrorString(glGetError()));

    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }


  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
