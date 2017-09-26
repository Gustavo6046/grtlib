#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Line.h"
#include "Camera.h"
#include "Vector.h"
#include "Raymath.h"
#include "RenderObj.h"

#include <math.h>


class Triangle :public RenderObj
{
    public:
        /** Default constructor */
        Triangle(Vector points[3], Vector color);

        std::vector< std::pair<Vector*, Vector*> > edges;
        Vector myColor;
        bool bIntersects(Ray* ray, double* dist);

    protected:
    private:
};

#endif // TRIANGLE_H
