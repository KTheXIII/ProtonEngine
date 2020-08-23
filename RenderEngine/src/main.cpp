#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main(int argc, char const* argv[]) {
    GLFWwindow* window;

    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(960, 540, "Render Engine!", NULL, NULL);
    glfwMakeContextCurrent(window);
    
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

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
