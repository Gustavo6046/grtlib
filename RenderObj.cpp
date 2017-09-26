#include "RenderObj.hpp"


bool RenderObj::bIntersects(Ray* ray, double* dist)
{
    return false; // to prevent ghost shapes by rogue RenderObj's
}

Vector RenderObj::center()
{
    return Vector(0, 0, 0);
}
