#pragma once

#include "test.hpp"
#include "../texture.hpp"

namespace test {

  class TextureTest : public Test {
    public:
      TextureTest();
      ~TextureTest();

      void OnUpdate(float deltaTime) override;
      void OnRender() override;

    private:
      float vertices[4 * 4];
      unsigned int indices[6];
      Renderer renderer;
      Shader shader;
      VertexArray va;
      VertexBuffer vb;
      VertexBufferLayout layout;
      IndexBuffer ib;
      Texture* texture = nullptr;

      void ImGuiSetup() override;
  };
}
