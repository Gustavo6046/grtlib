#ifndef RENDEROBJ_H
#define RENDEROBJ_H

#include "Raymath.h"

class RenderObj
{
public:
    bool bIntersects(Ray* ray, double* dist);

    Vector myColor;
};

#endif // RENDEROBJ_H
