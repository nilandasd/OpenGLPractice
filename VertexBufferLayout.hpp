#pragma once

#include "vendor/glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "vendor/GLFW/glfw3.h"

#include <vector>

struct VertexBufferElement {
  unsigned int type;
  unsigned int count;
  unsigned char normalized;

  static unsigned int SizeofType(unsigned int type) {
    switch (type) {
    case GL_FLOAT: return sizeof(GLfloat);
    case GL_UNSIGNED_INT: return sizeof(GLuint);
    case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
    }
    assert(false);
    return 0;
  }
};

class VertexBufferLayout {
  public:
    VertexBufferLayout(): m_stride(0) {};

    void Push(unsigned int type, unsigned int count, unsigned char normalized) {
      VertexBufferElement element = {
        type, 
        count,
        normalized
      };
      m_elements.push_back(element);
      m_stride += count * VertexBufferElement::SizeofType(type);
    }

    inline unsigned int getStride() const {
      return m_stride;
    }
    inline const std::vector<VertexBufferElement>&  getElements() const {
      return m_elements;
    }

  private:
    std::vector<VertexBufferElement> m_elements;
    unsigned int m_stride;
};
