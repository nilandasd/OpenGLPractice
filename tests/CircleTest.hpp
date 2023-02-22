#pragma once

#include "test.hpp"
#include "../vendor/glm/trigonometric.hpp"

#include <vector>

namespace test {

  class CircleTest : public Test {
    public:
      CircleTest();
      ~CircleTest();

      void OnUpdate(float deltaTime) override;
      void OnRender() override;

    private:
      std::vector<float> vertices;
      std::vector<unsigned int> indices;
      VertexBuffer* vb;
      IndexBuffer* ib;
      VertexBufferLayout* layout;
      VertexArray* va;
      Shader* shader;
      Renderer* renderer;

      float resolution = 10.0f;
      float radius= 0.5f;

      void ImGuiSetup() override;
      void generateCircleVertices(float r);
  };
}
