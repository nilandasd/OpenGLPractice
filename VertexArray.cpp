#include "VertexArray.hpp"

VertexArray::VertexArray() {
  glCall( glGenVertexArrays(1, &m_renderID) );
}

VertexArray::~VertexArray() {
	glCall( glDeleteVertexArrays(1, &m_renderID) );
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
  Bind();
  vb.Bind();
  const auto& elements = layout.getElements();
  unsigned int offset = 0;
  for (unsigned int i = 0; i < elements.size(); i++) {
    const auto& element = elements[i];
    glCall( glEnableVertexAttribArray(i) );
    glCall( glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset) );
    offset += element.count * VertexBufferElement::SizeofType(element.type);
  }
}

void VertexArray::Bind() const {
  glCall(glBindVertexArray(m_renderID));
}

void VertexArray::Unbind() const {
  glCall(glBindVertexArray(0));
}
