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
      Texture* catTexture = nullptr;
      Texture* treeTexture = nullptr;
      glm::mat4 proj;
      glm::mat4 view;
      glm::mat4 model;
      glm::vec3 translationA;
      glm::vec3 translationB;
      glm::vec3 translationC;
      glm::vec3 translationD;

      void ImGuiSetup() override;
  };
}
