#pragma once
#include "LessonShaders.h"

class LessonShader_Exercise2 : public LessonShaders
{
public:
    virtual void OnStart() override
    {
        LessonShaders::OnStart();
    }

    virtual void OnRender() override
    {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(m_shaderProgram);

        int vertexOffsetLocation = glGetUniformLocation(m_shaderProgram, "hOffset");
        glUniform1f(vertexOffsetLocation, 0.5f);

        glBindVertexArray(m_VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
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
            "uniform float hOffset;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x + hOffset, aPos.y, aPos.z, 1.0);\n"
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

