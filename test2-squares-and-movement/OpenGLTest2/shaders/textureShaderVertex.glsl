#version 400

uniform mat4 transform;

in vec2 position;

void main()
{
    gl_Position = transform * vec4(position, 0.0, 1.0);
}