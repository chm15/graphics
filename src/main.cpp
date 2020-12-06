#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string.h>


#include "linearmath/vec3.h"
#include "graphics/renderer.h"
#include "graphics/vertexbuffer.h"
#include "graphics/indexbuffer.h"
#include "graphics/vertexarray.h"

static unsigned int compileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        //glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char message[200];
        glGetShaderInfoLog(id, 200, &length, message);
        std::string shaderType = (type == GL_VERTEX_SHADER ? "vertex" : "fragment");
        std::cout << "Failed to compile " << shaderType << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

static unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}

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

    std::string vertexShader = 
    "#version 330 core\n"
    "\n"
    "layout(location = 0) in vec4 position;"
    "\n"
    "void main()\n"
    "{\n"
    "   gl_Position = position;\n"
    "}\n";
    std::string fragmentShader = 
    "#version 330 core\n"
    "\n"
    "layout(location = 0) out vec4 color;"
    "\n"
    "void main()\n"
    "{\n"
    "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";


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
    unsigned int shader = createShader(vertexShader, fragmentShader);
    glUseProgram(shader);


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

    glDeleteProgram(shader);

    // Terminate GLFW library
    }

    glfwTerminate();

    return 0;

}