#include "vertex_buffer.hpp"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
  glCall( glGenBuffers(1, &m_RenderID) );
  glCall( glBindBuffer(GL_ARRAY_BUFFER, m_RenderID) );
  glCall( glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW) );
}

VertexBuffer::~VertexBuffer() {
	glCall( glDeleteBuffers(1, &m_RenderID) );
}

void VertexBuffer::Bind() const {
  glCall( glBindBuffer(GL_ARRAY_BUFFER, m_RenderID) );
}

void VertexBuffer::Unbind() const {
  glCall( glBindBuffer(GL_ARRAY_BUFFER, 0) );
}
