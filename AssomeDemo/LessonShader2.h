#pragma once
#include "Renderer.h"
#include "Shader.h"

class LessonShader2 : public Renderer
{
public:
    // Inherited via Renderer
    virtual void OnStart() override;
    virtual void OnRender() override;
    virtual void OnEnd() override;
private:
    Shader* shader;
    GLuint VAO;
};

