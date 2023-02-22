#pragma once

#include "test.hpp"
#include "../texture.hpp"

#include <vector>

namespace test {

  class CubeTest : public Test {
    public:
      CubeTest();
      ~CubeTest();

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
      Texture* importantTexture = nullptr;

      float translate = 2.0f;
      glm::vec2 rotate = { 0.0f, 0.0f };

      void ImGuiSetup() override;
  };
}
