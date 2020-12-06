#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "linearmath/vec3.h"

#include "graphics/renderer.h"
#include "graphics/vertexbuffer.h"
#include "graphics/indexbuffer.h"
#include "graphics/vertexarray.h"


int main() {
    GLFWwindow* window;
    
    if(!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    // Scope to ensure everything is removed.
    {

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

    // TODO delete this
    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));


    // Vertex array
    VertexArray va;

    // Vertex buffer
    VertexBuffer vb(positions, 4*2*sizeof(float));

    // Describe data that will be found in the buffer to the graphics card
    VertexBufferLayout layout;
    layout.push<float>(2);
    va.addBuffer(vb, layout);

    // Index Buffer
    IndexBuffer ib(indices, 6);

    // Load shaders

    // TODO: Load shaders

    // Loop until user closes window
    while (!glfwWindowShouldClose(window)) {
        // Render
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        // Bind buffers
        va.bind();
        ib.bind();

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
    }

    glfwTerminate();

    return 0;

}