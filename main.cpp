#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main() {
    GLFWwindow* window;
    
    if(!glfwInit()) {
        return -1;
    }

    // Create context and window
    window = glfwCreateWindow(640, 480, "Game Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make window's context current
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error during glew init." << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;



    float positions[] = {
        -0.5,-0.5,
        0.5,-0.5,
        0.5,0.5,
        -0.5,0.5,
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };


    // Vertex buffer
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    // Fill buffer with data
    glBufferData(GL_ARRAY_BUFFER, 4*2*sizeof(float), positions, GL_STATIC_DRAW);
    // Describe data that will be found in the buffer to the graphics card
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    // Index Buffer
    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6* sizeof(unsigned int), indices, GL_STATIC_DRAW);
    // Load shaders

    // TODO: Load shaders

    // Loop until user closes window
    while (!glfwWindowShouldClose(window)) {
        // Render
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        // Swap buffers
        glfwSwapBuffers(window);

        // Handle events
        glfwPollEvents();

    }




    // Cleanup

    // Delete program (shader)

    //glDeleteProgram(shader)

    // Terminate GLFW library
    glfwTerminate();

    return 0;

}