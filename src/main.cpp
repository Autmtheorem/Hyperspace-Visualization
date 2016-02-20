#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>





// keyboard call back for future use
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {

}




// release all glfw resources
bool releaseGraphics(GLFWwindow* win) {
  glfwDestroyWindow(win);
  glfwTerminate();

  return true;
}

// Configures inital window and graphics display region
GLFWwindow* initializeGraphics() {
    if(!glfwInit()) {
      exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    GLFWwindow *win = glfwCreateWindow(800,600, "DEMO", NULL, NULL);
    glfwMakeContextCurrent(win);
    glfwSetKeyCallback(win, key_callback);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
      std::cout << "GLEW FAILED!!!!" << std::endl;
      exit(EXIT_FAILURE);
    }
    glViewport(0, 0, 800, 600);

    return win;
}

int main() {
  // main window
  GLFWwindow* win = initializeGraphics();

  // main graphics loop
  while(!glfwWindowShouldClose(win)) {
    glfwPollEvents();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(win);

  }

  bool closed = releaseGraphics(win);

  exit(EXIT_SUCCESS);
}
