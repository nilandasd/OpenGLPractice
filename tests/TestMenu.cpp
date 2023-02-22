#include "TestMenu.hpp"

namespace test {
  TestMenu::TestMenu() : listbox_item_current(-1), currentTest(nullptr), testNames { "Clear Color", "Triangle", "Textures", "Circle" } {
  };

  TestMenu::~TestMenu() {
    if (currentTest != nullptr) {
      delete currentTest;
    }
  };

  void TestMenu::OnUpdate(float timeDelta) {
    if (currentTest != nullptr)
      currentTest->OnUpdate(timeDelta);
  }

  void TestMenu::OnRender() {
    if (currentTest != nullptr) {
      currentTest->OnRender();
    } else {
      glCall( glClearColor(0.6f, 0.9f, 0.69f, 0.69f) );
      glCall( glClear(GL_COLOR_BUFFER_BIT) );
    }
  }

  void TestMenu::ImGuiSetup() {
    ImGuiNewFrame();

    if (currentTest == nullptr) {
      ImGui::Begin("Test Menu");
      const char* listbox_items[] = {
        testNames[0],
        testNames[1],
        testNames[2],
        testNames[3],
      };

      switch (listbox_item_current) {
        case 0: {
          currentTest = new ClearColorTest();
          break;
        }
        case 1: {
          currentTest = new TriangleTest();
          break;
        }
        case 2: {
          currentTest = new TextureTest();
          break;
        }
        case 3: {
          currentTest = new CircleTest();
          break;
        }
      }

      ImGui::ListBox("Basic Tests\n", &listbox_item_current, listbox_items, IM_ARRAYSIZE(listbox_items), 5);

      ImGui::End();
    } else {
      if (ImGui::Button("Back")) {
        delete currentTest;
        currentTest = nullptr;
        listbox_item_current = -1;
      } else {
        currentTest->ImGuiSetup();
      }
    }

    ImGuiRender();
  }

  void TestMenu::run() {
    OnUpdate(0.0f);
    OnRender();
    ImGuiSetup();
  }
}
