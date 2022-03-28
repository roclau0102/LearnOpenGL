#pragma once
#include "LessonTriangle.h"

class LessonTriangle_Exercise3 : public LessonTriangle
{
public:
    const char* fragmentShaderSourceYellow = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "}\0";

    // Inherited via RendererExercise
    virtual void OnStart() override;
    virtual void OnRender() override;
    virtual void OnEnd() override;
private:
    GLuint VAO[2], VBO[2];
    GLuint shaderProgramOrange, shaderProgramYellow;
};

