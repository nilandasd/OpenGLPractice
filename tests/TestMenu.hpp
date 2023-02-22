#pragma once

#include "test.hpp"
#include "ClearColorTest.hpp"
#include "TriangleTest.hpp"
#include "TextureTest.hpp"
#include "CircleTest.hpp"
#include "CubeTest.hpp"

#include <vector>
#include <string>

namespace test {
  class TestMenu: public Test {
    public:
      TestMenu();
      ~TestMenu();

      void run();

    private:
      Test* currentTest;
      std::vector<const char*> testNames;
      int listbox_item_current;

      void ImGuiSetup() override;
      void OnRender() override;
      void OnUpdate(float deltaTime) override;
  };
}
