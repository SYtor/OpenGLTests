#version 400

uniform sampler2D texture1;

in vec2 TextCoord;
out vec4 FragColor;

void main()
{
    FragColor = texture(texture1, TextCoord);
}