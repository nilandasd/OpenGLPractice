#pragma once

#include "test.hpp"

namespace test {

  class ClearColorTest : public Test {
    public:
      ClearColorTest();
      ~ClearColorTest();

      void OnUpdate(float deltaTime) override;
      void OnRender() override;

    private:
      float clearColor[4];

      void ImGuiSetup() override;
  };
}
