#include "vertexarray.h"


#include "renderer.h"

VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1, &rendererID));
}

VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArrays(1, &rendererID));
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
    // Bind vertex array
    bind();

    // Bind VertexBuffer so can tweak parameters in GPU.
    vb.bind();

    // Setup layout of VertexBuffer in GPU.
    const auto& elements = layout.getElements();
    unsigned int offset = 0;
    for (unsigned int i=0; i< elements.size(); i++) {
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type,
            element.normalized, layout.getStride(), (const void*)offset));
        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() const {
    GLCall(glBindVertexArray(rendererID));
}
void VertexArray::unbind() const {
    GLCall(glBindVertexArray(0));
}
