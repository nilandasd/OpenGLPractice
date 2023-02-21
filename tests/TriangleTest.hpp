#pragma once

#include "test.hpp"

namespace test {

  class TriangleTest : public Test {
    public:
      TriangleTest();
      ~TriangleTest();

      void OnUpdate(float deltaTime) override;
      void OnRender() override;

    private:
      float color[4];
      float vertices[6];
      unsigned int indices[3];
      Renderer renderer;
      Shader shader;
      VertexArray va;
      VertexBuffer vb;
      VertexBufferLayout layout;
      IndexBuffer ib;

      void ImGuiSetup() override;
  };
}
