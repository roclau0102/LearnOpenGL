#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

#include "Renderer.h"
#include "Exercise1.h"
#include "Exercise2.h"
#include "Exercise3.h"
#include "LessonShaders.h"

const int HEIGHT = 800;
const int WIDTH = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(HEIGHT, WIDTH, "AssomeDemo", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Renderer* renderer = new LessonShaders();
    renderer->OnStart();

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        renderer->OnRender();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    renderer->OnEnd();
    delete renderer;

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}