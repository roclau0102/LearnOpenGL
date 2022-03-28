#pragma once
#include "Renderer.h"

class LessonShaders : public Renderer
{
public:
    // Inherited via Renderer
    virtual void OnStart() override;
    virtual void OnRender() override;
    virtual void OnEnd() override;

private:
    GLuint m_VAO;
    GLuint m_shaderProgram;
};

