#pragma once

#include "VertexArray.hpp"
#include "index_buffer.hpp"
#include "shader.hpp"

class Renderer {
  public:
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void Clear() const;
  private:
};

