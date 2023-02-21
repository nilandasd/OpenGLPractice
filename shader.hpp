#pragma once

#include "util.hpp"

#include "vendor/glm/glm.hpp"
#include "vendor/glm/ext.hpp"

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>

struct ShaderProgramSource {
  std::string VertexSource;
  std::string FragmentSource;
};

class Shader {
  public:
    Shader(const std::string& filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void SetUniform1i(const std::string& name, int v0);
    void SetUniformMat4f(const std::string& name, const glm::mat4& v0);
  private:
    unsigned int renderID;
    std::string filepath;
    std::unordered_map<std::string, int> uniform_location_cache;

    unsigned int GetUniformLocation(const std::string& name);
    bool CompileShader();
    int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    unsigned int CompileShader(unsigned int type, const std::string& source);
    ShaderProgramSource ParseShader();
};
