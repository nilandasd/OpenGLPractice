#pragma once

#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_glfw.h"
#include "../vendor/imgui/imgui_impl_opengl3.h"

#include "../render.hpp"

namespace test {

  class Test {
    public:
      Test() {}
      virtual ~Test() {}

      virtual void OnUpdate(float deltaTime) {}
      virtual void OnRender() {}
      void OnImGuiRender() {
        ImGuiNewFrame();
        ImGuiSetup();
        ImGuiRender();
      }

      virtual void ImGuiSetup() {}

      void ImGuiNewFrame() const {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
      }

      void ImGuiRender() const {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
      }

  };
}
