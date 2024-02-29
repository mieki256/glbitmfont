// GLFW3 + Bitmap Font draw sample
//
// by mieki256 , License : CC0 / Public Domain
// Last updated: <2024/02/29 08:57:18 +0900>

#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

#include "glbitmfont.h"

#define SCR_W 512
#define SCR_H 288

void error_callback(int error, const char *description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}

int main(void)
{
  GLFWwindow *window;
  GLuint tex_id;

  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
  {
    // Initialization failed
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1); // set OpenGL 1.1
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  // create window
  window = glfwCreateWindow(SCR_W, SCR_H, "Bitmap Font Sample", NULL, NULL);
  if (!window)
  {
    // Window or OpenGL context creation failed
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);

  glfwSwapInterval(1);

  int scrw, scrh;
  glfwGetFramebufferSize(window, &scrw, &scrh);
  glViewport(0, 0, scrw, scrh);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, scrw, scrh, 0, 1.0, -1.0);

  int count = 0;
  int kind = 0;

  // main loop
  while (!glfwWindowShouldClose(window))
  {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // draw text
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glRasterPos2f(20, 64);
    glBitmapFontDrawString("Hello World", kind);

    glfwSwapBuffers(window);
    glfwPollEvents();

    count++;
    if ((count % 60) == 59)
    {
      kind = (kind + 1) % GL_FONT_MAX;
    }
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
