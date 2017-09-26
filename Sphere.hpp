#ifndef SPHERE_H
#define SPHERE_H

#include "Vector.hpp"
#include "RenderObj.hpp"


double intersectRaySphere(Vector rO, Vector rV, Vector sO, double sR);

class Sphere :public RenderObj
{
public:
    Sphere(Vector pos, double radius, Vector color);
    bool bIntersects(Ray* ray, double* dist);
    Vector center();

    Vector myColor;
    Vector myPos;
    double myRadius;
};

#endif // SPHERE_H
