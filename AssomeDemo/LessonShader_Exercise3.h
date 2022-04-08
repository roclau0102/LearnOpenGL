#pragma once
#include "LessonShaders.h"

class LessonShader_Exercise3 : public LessonShaders
{
public:
    void OnStart() override
    {
        LessonShaders::OnStart();
    }

    void OnRender() override
    {
        LessonShaders::OnRender();
    }

    void OnEnd() override
    {
        LessonShaders::OnEnd();
    }

protected:
    virtual const char* GetVertexShaderSource() override
    {
        return
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "out vec3 ourColor;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos, 1.0);\n"
            "   ourColor = aPos;\n"
            "}\0";
    }

    virtual const char* GetFragmentShaderSource() override
    {
        return
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "in vec3 ourColor;\n"
            "void main()\n"
            "{\n"
            "    FragColor = vec4(ourColor, 1.0f);\n"
            "}\0";
    }
};