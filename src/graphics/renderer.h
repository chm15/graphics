#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <WinBase.h>
#include <iostream>

#define ASSERT(x) if(!(x)) std::cout << "Assert in: " << __FILE__ <<  "\nLine " << __LINE__ << std::endl;
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall( const char* function, const char* file, int line);




#endif