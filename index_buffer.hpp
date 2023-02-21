#pragma once

#include "util.hpp"

class IndexBuffer {
  public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int getCount() const { return m_Count; }

  private:
    unsigned int m_RenderID;
    unsigned int m_Count;
};
