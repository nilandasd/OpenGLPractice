#include "TriangleTest.hpp"

namespace test {
  TriangleTest::TriangleTest()
    : shader( Shader("res/shaders/TriangleTest.shader") ),
      indices {0, 1, 2},
      vertices {
        -0.5f, -0.4f,
         0.6f, -0.5f,
         0.0f,  0.4f
      },
      ib(IndexBuffer(indices, 3)),
      vb(VertexBuffer(vertices, 2 * 3 * sizeof(float))),
      color {0.2f, 0.4f, 0.9f, 1.0f} {

    layout.Push(GL_FLOAT, 2, GL_TRUE);
    va.AddBuffer(vb, layout);

    shader.Bind();
    shader.SetUniform4f("u_Color", color[0], color[1], color[2], color[3]);

    glCall( glClearColor(0.0f, 0.0f, 0.0f, 0.0f) );
  }

  TriangleTest::~TriangleTest() {
  }

  void TriangleTest::OnUpdate(float delateTime) {
  }

  void TriangleTest::OnRender() {
    glCall( glClear(GL_COLOR_BUFFER_BIT) );

    renderer.Draw(va, ib, shader);
    shader.SetUniform4f("u_Color", color[0], color[1], color[2], color[3]);
  }

  void TriangleTest::ImGuiSetup() {
    ImGui::ColorEdit4("Triangle Color", color);
  }
}
