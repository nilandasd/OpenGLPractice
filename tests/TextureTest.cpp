#include "TextureTest.hpp"

namespace test {
  TextureTest::TextureTest()
    : shader( Shader("res/shaders/TextureTest.shader") ),
      indices {0, 1, 2, 0, 2, 3},
      vertices {
        450.0f, 450.0f, 0.0f, 0.0f,
        550.0f, 450.0f, 1.0f, 0.0f,
        550.0f, 550.0f, 1.0f, 1.0f,
        450.0f, 550.0f, 0.0f, 1.0f
      },
      ib(IndexBuffer(indices, 6)),
      vb(VertexBuffer(vertices, 4 * 4 * sizeof(float))) {

    layout.Push(GL_FLOAT, 2, GL_TRUE);
    layout.Push(GL_FLOAT, 2, GL_TRUE);
    va.AddBuffer(vb, layout);
    treeTexture = new Texture("res/textures/tree.jpg");
    catTexture = new Texture("res/textures/image.jpg");

    // projection matrix
    proj = glm::ortho(0.0f, 1000.0f, 0.0f, 1000.0f, -1.0f, 1.0f);

    // view matrix
    glm::mat4 ident = glm::mat4(1.0f);
    glm::vec3 trvec = glm::vec3(0, 0, 0);
    view = glm::translate(ident, trvec);
    translationA = glm::vec3( 100,    0, 0);
    translationB = glm::vec3(   0,  100, 0);
    translationC = glm::vec3(   0,    0, 0);
    translationD = glm::vec3(   100, 100, 0);
  }

  TextureTest::~TextureTest() {
    delete catTexture;
    delete treeTexture;
  }

  void TextureTest::OnUpdate(float delateTime) {
  }

  void TextureTest::OnRender() {
    {
      shader.Bind();
      treeTexture->Bind(0);
      glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
      glm::mat4 mvp = proj * view * model;
      shader.SetUniformMat4f("u_MVP", mvp);
      shader.SetUniform1i("u_Texture", 0);
      renderer.Draw(va, ib, shader);
    }
    {
      shader.Bind();
      treeTexture->Bind(0);
      glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
      glm::mat4 mvp = proj * view * model;
      shader.SetUniformMat4f("u_MVP", mvp);
      shader.SetUniform1i("u_Texture", 0);
      renderer.Draw(va, ib, shader);
    }
    {
      shader.Bind();
      catTexture->Bind(0);
      glm::mat4 model = glm::translate(glm::mat4(1.0f), translationC);
      glm::mat4 mvp = proj * view * model;
      shader.SetUniformMat4f("u_MVP", mvp);
      shader.SetUniform1i("u_Texture", 0);
      renderer.Draw(va, ib, shader);
    }
    {
      shader.Bind();
      catTexture->Bind(0);
      glm::mat4 model = glm::translate(glm::mat4(1.0f), translationD);
      glm::mat4 mvp = proj * view * model;
      shader.SetUniformMat4f("u_MVP", mvp);
      shader.SetUniform1i("u_Texture", 0);
      renderer.Draw(va, ib, shader);
    }
  }

  void TextureTest::ImGuiSetup() {
    //ImGui::ColorEdit4("Triangle Color", color);
  }
}
