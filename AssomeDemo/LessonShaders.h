#pragma once
#include "Renderer.h"
#include "Shader.h"

class LessonShaders : public Renderer
{
public:
    // Inherited via Renderer
    virtual void OnStart() override;
    virtual void OnRender() override;
    virtual void OnEnd() override;

protected:
    virtual const char* GetVertexShaderSource()
    {
        return
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "layout (location = 1) in vec3 aColor;\n"
            "out vec3 ourColor;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos, 1.0);\n"
            "   ourColor = aColor;\n"
            "}\0";
    }

    virtual const char* GetFragmentShaderSource()
    {
        return 
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "// uniform vec4 ourColor; // we set this variable in the OpenGL code.\n"
            "in vec3 ourColor;\n"
            "void main()\n"
            "{\n"
            "    FragColor = vec4(ourColor, 1.0f);\n"
            "}\0";
    }

protected:
    GLuint m_VAO;
    GLuint m_shaderProgram;
};

