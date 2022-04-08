#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    GLuint ID;

    Shader(const char* vShaderPath, const char* fShaderPath)
    {
        std::string vShaderCode;
        std::string fShaderCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            vShaderFile.open(vShaderPath);
            fShaderFile.open(fShaderPath);

            std::stringstream vShaderStream;
            std::stringstream fShaderStream;

            vShaderStream << vShaderFile.rdbuf();       // stream ?? << 
            fShaderStream << fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vShaderCode = vShaderStream.str();
            fShaderCode = fShaderStream.str();
        }
        catch (const std::exception&)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }

        const char* vertexShaderSource = vShaderCode.c_str();
        const char* fragmentShaderSource = fShaderCode.c_str();

        GLuint vertexShader;
        GLuint fragmentShader;

        // vertex shader
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        CheckCompileErrors(vertexShader, "VERTEX");

        // fragment shader
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        CheckCompileErrors(fragmentShader, "FRAGMENT");

        // shader program
        ID = glCreateProgram();
        glAttachShader(vertexShader, fragmentShader);
        glLinkProgram(ID);
        CheckCompileErrors(ID, "PROGRAM");

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    ~Shader()
    {
        glDeleteProgram(ID);
    }

    void Use()
    {
        glUseProgram(ID);
    }

    void SetBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }

    void SetInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    void SetFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

private:
    void CheckCompileErrors(GLuint shader, std::string type)
    {
        int success;
        char info[1024];

        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 512, NULL, info);
                std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << info << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 512, NULL, info);
                std::cout << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << info << std::endl;
            }
        }

    }
};

#endif // SHADER_H