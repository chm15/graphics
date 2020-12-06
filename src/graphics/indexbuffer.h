#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

class IndexBuffer {
    private:
    unsigned int rendererID;
    unsigned int count;

    public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    unsigned int getCounts() const { return count; }
};


#endif