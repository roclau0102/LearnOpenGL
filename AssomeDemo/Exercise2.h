#pragma once
#include "RendererExercise.h"

class Exercise2 : public RendererExercise
{
public:
    virtual void OnStart() override;
    virtual void OnRender() override;
    virtual void OnEnd() override;
private:
    GLuint VAO[2], VBO[2];
    GLuint shaderProgram;
};

