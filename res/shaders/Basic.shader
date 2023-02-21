#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_texCoord;

uniform mat4 MVP;

void main() {
  gl_Position = MVP * position;
  v_texCoord = texCoord;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_texCoord;

uniform sampler2D u_Texture;

void main() {
  vec4 texColor = texture(u_Texture, v_texCoord);
  color = texColor;
}
