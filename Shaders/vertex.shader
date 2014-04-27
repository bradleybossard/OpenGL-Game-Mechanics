#version 410

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec4 offset;

out VS_OUT
{
  vec4 color;
} vs_out;

void main()
{
  gl_Position = position + offset;

  vs_out.color = color;
}
