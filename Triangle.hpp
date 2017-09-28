#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Line.hpp"
#include "Camera.hpp"
#include "Vector.hpp"
#include "Raymath.hpp"
#include "RenderObj.hpp"

#include <math.h>


class Triangle :public RenderObj
{
    public:
        /** Default constructor */
        Triangle(Vector points[3], Vector color);
        std::vector< std::pair<Vector*, Vector*> > edges;
        Vector myColor;

        Vector center();
        bool bIntersects(Ray* ray, double* dist);

    protected:
    private:
};

#endif // TRIANGLE_H
