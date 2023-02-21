#include "ClearColorTest.hpp"

namespace test {
  ClearColorTest::ClearColorTest() : clearColor { 0.2f, 0.3f, 0.8f, 1.0f } {
  }

  ClearColorTest::~ClearColorTest() {
  }

  void ClearColorTest::OnUpdate(float delateTime) {
  }

  void ClearColorTest::OnRender() {
    glCall( glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]) );
    glCall( glClear(GL_COLOR_BUFFER_BIT) );
  }

  void ClearColorTest::ImGuiSetup() {
    ImGui::ColorEdit4("Clear Color", clearColor);
  }
}
