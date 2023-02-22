#include "CubeTest.hpp"

namespace test {
  CubeTest::CubeTest() {
    vertices = {
      -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
       0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
       0.5f,  0.5f, 0.5f, 1.0f, 1.0f,
      -0.5f,  0.5f, 0.5f, 0.0f, 1.0f,
 
      -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, // 4
       0.5f, -0.5f, -0.5f, 0.0f, 0.0f, // 5
       0.5f,  0.5f, -0.5f, 0.0f, 1.0f, // 6
      -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, // 7
    };

    indices = {
      // front face
      0, 1, 3,
      2, 3, 1,
      // back face
      5, 4, 6,
      7, 6, 4,
      // top face
      2, 6, 3,
      7, 3, 6,
      // bottom face
      0, 4, 1,
      5, 1, 4,
      // left face
      3, 7, 0,
      4, 0, 7,
      // right face
      2, 1, 6,
      5, 6, 1
    };

    vb = new VertexBuffer(&vertices[0], vertices.size() * sizeof(float));
    ib = new IndexBuffer(&indices[0], indices.size());
    layout = new VertexBufferLayout;
    layout->Push(GL_FLOAT, 3, GL_TRUE);
    layout->Push(GL_FLOAT, 2, GL_TRUE);
    va = new VertexArray;
    va->AddBuffer(*vb, *layout);
    shader = new Shader("res/shaders/CubeTest.shader");
    shader->Bind();
    importantTexture = new Texture("res/textures/important_document_69.png");
    renderer = new Renderer;

    glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 1.0f, 0.1f, 100.f);
    glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -translate));
    View = glm::rotate(View, rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    View = glm::rotate(View, rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    glm::mat4 mvp = Projection * View * Model;

    shader->SetUniformMat4f("u_MVP", mvp);

    glCall(glEnable(GL_DEPTH_TEST));
    glCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f) );
    glCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
  }

  CubeTest::~CubeTest() {
    delete vb;
    delete ib;
    delete layout;
    delete va;
    delete shader;
    delete renderer;

    glCall(glDisable(GL_DEPTH_TEST));
  }

  void CubeTest::OnUpdate(float delateTime) {
  }

  void CubeTest::OnRender() {
    glCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    shader->Bind();
    importantTexture->Bind(0);

    glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 1.0f, 0.1f, 100.f);
    glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -translate));
    View = glm::rotate(View, rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    View = glm::rotate(View, rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    glm::mat4 mvp = Projection * View * Model;

    shader->SetUniformMat4f("u_MVP", mvp);
    shader->SetUniform1i("u_Texture", 0);
    renderer->Draw(*va, *ib, *shader);
  }

  void CubeTest::ImGuiSetup() {
    ImGui::SliderFloat2("rotate", &rotate[0], -5.0f, 5.0f);
    ImGui::SliderFloat("translate", &translate, 0.0f, 5.0f);
  }
}
