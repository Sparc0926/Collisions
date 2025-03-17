#include <stdio.h>
#include <windows.h>
#include <glew.h>
#include <glfw3.h>
#include <Block.h>

#define WIN_HEIGHT 700  // 255 * 4
#define WIN_WIDTH 1000   // 255 * 6

int main(void)
{
    GLFWwindow* window;
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Error: GLFW is not initialized!\n");
        return -1;
    }
    // Disable window resizing
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    // Create a GLFW window and its context
    if (!(window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Collisions", NULL, NULL))) {
        printf("Error: GLFW window is not created!\n");
        glfwTerminate();
        return -1;
    }
    // Make the window's context current
    glfwMakeContextCurrent(window);
    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        printf("Error: GLEW is not initialized!\n");
        return -1;
    }
    // Initialize blocks
    BeginBlock();
    AddBlock(0, 0, 0, 100, -1, -1);
    // Window loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the sreen
        glClear(GL_COLOR_BUFFER_BIT);

        UpdateBlock();
        DrawBlock();
        // Swap front and back buffers
        glfwSwapBuffers(window);
        // Poll and process events
        glfwPollEvents();
        Sleep(10);
    }
    EndBlock();
    glfwDestroyWindow(window);
    glfwTerminate();
   
    return 0;
}