#include <iostream>

#include "GLFW/glfw3.h"

int main(int argc, char const* argv[]) {
    GLFWwindow* window;

    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(960, 540, "Render Engine!", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(255. / 255., 66. / 255., 98. / 255., 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);  // Swap front and back buffers
        glfwPollEvents();         // Poll for and process events
    }

    glfwTerminate();
    return 0;
}
