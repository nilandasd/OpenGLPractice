#pragma once

#include "vendor/glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "vendor/GLFW/glfw3.h"

#include <iostream>

class FPS {
  public:
    FPS(): prevTime(glfwGetTime()), frameCount(0) {};

    void track() {
      double currentTime = glfwGetTime();
      frameCount++;
      // If a second has passed.
      if ( currentTime - prevTime >= 1.0 ) {
          // Display the frame count here any way you want.
        // std::cout << frameCount << std::endl;
        frameCount = 0;
        prevTime = currentTime;
      }
    };

  private:
    unsigned int frameCount;
    unsigned int prevTime;
};
