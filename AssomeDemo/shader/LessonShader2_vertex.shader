#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
  
out vec3 ourColor; // output a color to the fragment shader

void main()
{
    vec3 newPos = aPos;
    newPos.y = -1 * newPos.y;
    // gl_Position = vec4(newPos, 1.0);
    gl_Position = vec4(aPos, 1.0);
    // gl_Position = vec4(1.0, 1.0, 1.0, 1.0);
    ourColor = vec3(1.0, 0.0, 0.0);
    // ourColor = aColor; // set ourColor to the input color we got from the vertex data
}      