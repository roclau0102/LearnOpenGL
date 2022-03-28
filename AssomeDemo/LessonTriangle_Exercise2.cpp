#include "LessonTriangle_Exercise2.h"

void LessonTriangle_Exercise2::OnStart()
{
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

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

void LessonTriangle_Exercise2::OnRender()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(VAO[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void LessonTriangle_Exercise2::OnEnd()
{
    glDeleteProgram(shaderProgram);
}
