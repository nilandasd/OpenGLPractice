#include "index_buffer.hpp"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
  :m_Count(count)
{
  glCall( glGenBuffers(1, &m_RenderID) );
  glCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID) );
  glCall( glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW) );
}

IndexBuffer::~IndexBuffer() {
	glCall( glDeleteBuffers(1, &m_RenderID) );
}

void IndexBuffer::Bind() const {
  glCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID) );
}

void IndexBuffer::Unbind() const {
  glCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0) );
}
