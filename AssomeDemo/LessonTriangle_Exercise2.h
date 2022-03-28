#pragma once
#include "LessonTriangle.h"

class LessonTriangle_Exercise2 : public LessonTriangle
{
public:
    virtual void OnStart() override;
    virtual void OnRender() override;
    virtual void OnEnd() override;
private:
    GLuint VAO[2], VBO[2];
    GLuint shaderProgram;
};

