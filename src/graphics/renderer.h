#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <WinBase.h>
#include <iostream>

#define ASSERT(x) if(!(x)) DebugBreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall( const char* function, const char* file, int line);




#endif