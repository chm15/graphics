#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H
#pragma once

#include <vector>
#include <GL/glew.h>
#include "renderer.h"

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned int normalized;

    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 4;
        }
        ASSERT(false);
        return 0;
    }
};


/*
@param count The number of components per attribute, must be 1, 2, 3, or 4
@param stride The byte offset between consecutive generic vertex attributes
*/
class VertexBufferLayout {
    private:
    std::vector<VertexBufferElement> elements;
    unsigned int stride;

    public:
    VertexBufferLayout() : stride(0) {}

    template<typename T>
    void push(unsigned int count);
        //static_assert(false);

    inline const std::vector<VertexBufferElement> getElements() const {
        return elements;
    }

    inline unsigned int getStride() const { return stride; }
};









#endif