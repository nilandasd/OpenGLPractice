#include "render.hpp"

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
    shader.Bind();
    va.Bind();
    ib.Bind();
		glCall( glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr) );
}

void Renderer::Clear() const {
  glCall( glClear(GL_COLOR_BUFFER_BIT) );
}
