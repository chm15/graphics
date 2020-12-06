#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "vertexbuffer.h"
#include "vertexbufferlayout.h"

class VertexArray {
    private:
    unsigned int rendererID;

    public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;

};

#endif