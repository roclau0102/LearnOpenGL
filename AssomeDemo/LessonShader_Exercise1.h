#pragma once
#include "LessonShaders.h"

class LessonShader_Exercise1 : public LessonShaders
{
public:
    virtual void OnStart() override
    {
        LessonShaders::OnStart();
    }

    virtual void OnRender() override
    {
        LessonShaders::OnRender();
    }

    virtual void OnEnd() override
    {
        LessonShaders::OnEnd();
    }

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
            "   vec3 p = aPos;\n"
            "   p.y = -1.0 * p.y;\n"
            "   gl_Position = vec4(p, 1.0);\n"
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
};

