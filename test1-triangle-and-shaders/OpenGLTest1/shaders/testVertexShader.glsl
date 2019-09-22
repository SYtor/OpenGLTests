#version 400

uniform float val;
in vec2 position;

void main()
{
    float x = position.x + val;
    float y = position.y - val;
    gl_Position = vec4(x, y, 0.0, 1.0);
}
