#include "Exercise3.h"

void Exercise3::OnStart()
{
    unsigned int vertexShader, fragmentShaderOrange, fragmentShaderYellow;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
    fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    glShaderSource(fragmentShaderOrange, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShaderOrange);

    glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSourceYellow, NULL);
    glCompileShader(fragmentShaderYellow);

    shaderProgramOrange = glCreateProgram();
    shaderProgramYellow = glCreateProgram();

    glAttachShader(shaderProgramOrange, vertexShader);
    glAttachShader(shaderProgramOrange, fragmentShaderOrange);
    glLinkProgram(shaderProgramOrange);

    glAttachShader(shaderProgramYellow, vertexShader);
    glAttachShader(shaderProgramYellow, fragmentShaderYellow);
    glLinkProgram(shaderProgramYellow);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShaderOrange);
    glDeleteShader(fragmentShaderYellow);

    float triangleVertices[] = {
        -1.0f, 0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
    };

    float triangleVertices2[] = {
        0.5f, 0.5f, 0.0f,
        1.0f, -0.5f, 0.0f,
        0.0f, -0.5f, 0.0f,
    };

    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);

    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices2), triangleVertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Exercise3::OnRender()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgramOrange);
    glBindVertexArray(VAO[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(shaderProgramYellow);
    glBindVertexArray(VAO[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Exercise3::OnEnd()
{
    glDeleteProgram(shaderProgramOrange);
    glDeleteProgram(shaderProgramYellow);
}
