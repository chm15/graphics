#include "vertexbufferlayout.h"



template<>
void VertexBufferLayout::push<float>(unsigned int count) {
    elements.push_back({GL_FLOAT, count, GL_FALSE});
    stride += sizeof(float) * count;
}

template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count) {
    elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    stride += sizeof(unsigned int) * count;
}

template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count) {
    elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    stride += sizeof(unsigned char) * count;
}
