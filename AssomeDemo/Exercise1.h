#pragma once
#include "RendererExercise.h"

class Exercise1 : public RendererExercise
{
public:
    void OnStart() override;
    void OnEnd() override;
    void OnRender() override;
private:
    unsigned int VAO, VBO;
    unsigned int shaderProgram;
};

