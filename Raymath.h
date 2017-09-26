#ifndef RAYMATH_H
#define RAYMATH_H

#include "Camera.h"


struct Ray
{
    Vector start, dir;
};

double lerp(double a, double b, double f);
double fovtan(double fov, double i);
double dfovtan(double fov, double i);
Vector fromPolar(double pitch, double yaw);
Ray camlerp(Camera* cam, double stepX, double stepY);

#endif // RAYMATH_H
