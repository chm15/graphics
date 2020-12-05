#ifndef VEC3_H
#define VEC3_h

#include "vec.h"

class Vec3 : public Vec<3> {
    public:
    float x = elements[0];
    float y = elements[1];
    float z = elements[2];
    using Vec<3>::Vec;
    Vec3(float x, float y, float z) : x(x), y(y), z(z) { }
};

class Vec4 : public Vec<4> {
    public:
    float x = elements[0];
    float y = elements[1];
    float z = elements[2];
    float w = elements[3];
    using Vec<4>::Vec;
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
};

#endif