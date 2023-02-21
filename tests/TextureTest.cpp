#include "TextureTest.hpp"

namespace test {
  TextureTest::TextureTest()
    : shader( Shader("res/shaders/TextureTest.shader") ),
      indices {0, 1, 2, 0, 2, 3},
      vertices {
        -0.5f, -0.5f, 0.0f, 0.0f,
         0.5f, -0.5f, 1.0f, 0.0f,
         0.5f,  0.5f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 1.0f
      },
      ib(IndexBuffer(indices, 6)),
      vb(VertexBuffer(vertices, 4 * 4 * sizeof(float))) {
    layout.Push(GL_FLOAT, 2, GL_TRUE);
    layout.Push(GL_FLOAT, 2, GL_TRUE);
    va.AddBuffer(vb, layout);
    texture = new Texture("res/textures/image.png");
    texture->Bind();
    shader.Bind();
    shader.SetUniform1i("u_Texture", 0);
  }

  TextureTest::~TextureTest() {
    delete texture;
  }

  void TextureTest::OnUpdate(float delateTime) {
  }

  void TextureTest::OnRender() {
    renderer.Draw(va, ib, shader);
  }

  void TextureTest::ImGuiSetup() {
    //ImGui::ColorEdit4("Triangle Color", color);
  }
}
