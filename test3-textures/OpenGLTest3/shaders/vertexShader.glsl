#version 400

uniform mat4 transform;

in vec2 position;
in vec2 texture_coordinate;

out vec2 TextCoord;

void main()
{
    gl_Position = transform * vec4(position, 0.0, 1.0);
    TextCoord = texture_coordinate;
}