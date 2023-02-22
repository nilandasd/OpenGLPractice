
#include "CircleTest.hpp"

namespace test {
  CircleTest::CircleTest() {
    generateCircleVertices(resolution);

    vb = new VertexBuffer(&vertices[0], vertices.size() * sizeof(float));
    ib = new IndexBuffer(&indices[0], indices.size());
    layout = new VertexBufferLayout;
    layout->Push(GL_FLOAT, 2, GL_TRUE);
    va = new VertexArray;
    va->AddBuffer(*vb, *layout);
    shader = new Shader("res/shaders/CircleTest.shader");
    shader->Bind();
    renderer = new Renderer;

    glCall( glClearColor(0.0f, 0.0f, 0.0f, 0.0f) );
  }

  CircleTest::~CircleTest() {
    delete vb;
    delete ib;
    delete layout;
    delete va;
    delete shader;
    delete renderer;
  }

  void CircleTest::OnUpdate(float delateTime) {
  }

  void CircleTest::OnRender() {
    glCall( glClear(GL_COLOR_BUFFER_BIT) );
    renderer->Draw(*va, *ib, *shader);
  }

  void CircleTest::ImGuiSetup() {
    ImGui::SliderFloat("Resolution", &resolution, 1.0f, 120.0f);
    ImGui::SliderFloat("Radius", &radius, 0.1f, 1.0f);
    if (ImGui::Button("Update")) {
      generateCircleVertices(ceil(360.0f / resolution));

      delete vb;
      delete ib;
      delete layout;
      delete va;
      delete shader;
      delete renderer;

      vb = new VertexBuffer(&vertices[0], vertices.size() * sizeof(float));
      ib = new IndexBuffer(&indices[0], indices.size());
      layout = new VertexBufferLayout;
      layout->Push(GL_FLOAT, 2, GL_TRUE);
      va = new VertexArray;
      va->AddBuffer(*vb, *layout);
      shader = new Shader("res/shaders/CircleTest.shader");
      shader->Bind();
      renderer = new Renderer;
    }
  }

  void CircleTest::generateCircleVertices(float resolution) {
    float x_prev = 1.0f;
    float y_prev = 0.0f;
    float x = 1.0f;
    float y = 0.0f;

    vertices.clear();
    indices.clear();

    // center vertex
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    // first perimeter vertex
    vertices.push_back(radius);
    vertices.push_back(0.0f);

    for (float i = (360.0f / resolution); i <= 360; i += 360.0f / resolution) {
      x_prev = x;
      y_prev = y;
      x = radius * glm::cos(glm::radians(i));
      y = radius * glm::sin(glm::radians(i));
      vertices.push_back(x);
      vertices.push_back(y);

      indices.push_back(0);
      indices.push_back((vertices.size() / 2) - 2);
      indices.push_back((vertices.size() / 2) - 1);
    }
  }
}
