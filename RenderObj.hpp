#ifndef RENDEROBJ_H
#define RENDEROBJ_H

#include "Raymath.hpp"

class RenderObj
{
public:
    bool bIntersects(Ray* ray, double* dist);
    Vector center();

    Vector myColor;
};

#endif // RENDEROBJ_H
