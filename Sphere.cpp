#include "Vector.hpp"
#include "Sphere.hpp"


double intersectRaySphere(Vector rO, Vector rV, Vector sO, double sR)
{
   Vector Q = sO - rO;
   double c = Q.sqlen();
   double v = Q.dot(rV);
   double d = sR*sR - (c - v*v);

   // If there was no intersection, return -1
   if (d < 0.0) return (-1.0f);

   // Return the distance to the [first] intersecting point
   return (v - sqrt(d));
}

bool Sphere::bIntersects(Ray* ray, double* dist)
{
    *dist = intersectRaySphere(ray->start, ray->dir, myPos, myRadius);

    return *dist != -1.0f;
}

Sphere::Sphere(Vector pos, double radius, Vector color)
{
    myPos = pos;
    myColor = color;
    myRadius = radius;
}
