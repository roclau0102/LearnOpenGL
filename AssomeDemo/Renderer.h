#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

class Renderer
{
public:
    virtual void OnStart() = 0;
    virtual void OnRender() = 0;
    virtual void OnEnd() = 0;
};

