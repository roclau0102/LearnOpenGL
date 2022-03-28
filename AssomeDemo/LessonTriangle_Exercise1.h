#pragma once
#include "LessonTriangle.h"

class LessonTriangle_Exercise1 : public LessonTriangle
{
public:
    void OnStart() override;
    void OnEnd() override;
    void OnRender() override;
private:
    unsigned int VAO, VBO;
    unsigned int shaderProgram;
};

