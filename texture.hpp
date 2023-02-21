#pragma once

#include "vendor/stb_image/stb_image.hpp"
#include "util.hpp"

class Texture {
  public:
    Texture(const std::string& fp);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

    inline int GetWidth() const { return width; }
    inline int GetHeight() const { return height; }

  private:
    unsigned int glid;
    int width, height, bpp;
    std::string filepath;
    unsigned char* local_buffer;
};
