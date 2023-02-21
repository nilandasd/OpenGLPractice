#pragma once

#include <iostream>

#include "vendor/glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "vendor/GLFW/glfw3.h"

#define glCall(x) GLClearError();\
    x;\
    assert(GLCheckError())

void GLClearError();

bool GLCheckError();
