#include "texture.hpp"

Texture::Texture(const std::string& fp)
  :glid(0), width(0), height(0), bpp(0),
  filepath(fp), local_buffer(nullptr) {

  stbi_set_flip_vertically_on_load(1);
  local_buffer = stbi_load(filepath.c_str(), &width, &height, &bpp, 4);

  glCall(glGenTextures(1, &glid));
  glCall(glBindTexture(GL_TEXTURE_2D, glid));
  glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
  glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
  glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
  glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

  glCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, local_buffer));
  Unbind();

  if (local_buffer)
    stbi_image_free(local_buffer);
};

Texture::~Texture() {
  glCall(glDeleteTextures(1, &glid));
}

void Texture::Bind(unsigned int slot /* = 0 */) const {
  glCall(glActiveTexture(GL_TEXTURE0 + slot));
  glCall(glBindTexture(GL_TEXTURE_2D, glid));
}

void Texture::Unbind() const {
  glCall(glBindTexture(GL_TEXTURE_2D, 0));
}
