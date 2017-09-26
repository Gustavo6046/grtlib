#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.hpp"


struct Camera {
    Vector position;
    Vector rotation;
    double fov;
};

#endif // CAMERA_H
