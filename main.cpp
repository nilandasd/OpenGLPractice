#include "tests/TestMenu.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

GLFWwindow* glInit() {
  GLFWwindow* window;

  assert(glfwInit());

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(1000, 1000, "Hello Triangles", NULL, NULL);
  if (!window) {
    std::cout << "FATAL: Failed to create GLFW window" << std::endl;
    glfwTerminate();
    assert(false);
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "FATAL: Failed to initialize GLAD" << std::endl;
    assert(false);
  } 

  fprintf(stdout, "INFO: GL version: %s\n", glGetString(GL_VERSION));

  glCall( glClearColor(0.2f, 0.3f, 0.7f, 1.0f) );
  glCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
  glCall(glEnable(GL_BLEND));

  return window;
}

void initImGui(GLFWwindow* window) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
}

void shutdownImGui() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

int main() {
  GLFWwindow* window = glInit();
  test::TestMenu testMenu;

  initImGui(window);

  while (!glfwWindowShouldClose(window)) {
    glCall( glClear(GL_COLOR_BUFFER_BIT) );

    testMenu.run();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  shutdownImGui();
  glfwTerminate();
  return 0;
}
