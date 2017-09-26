#include "Triangle.h"
#include "Raymath.h"
#include "Camera.h"


extern "C" int intersect_triangle3(double orig[3], double dir[3],
			double vert0[3], double vert1[3], double vert2[3],
			double *t, double *u, double *v);

Triangle::Triangle(Vector points[3], Vector _color)
{
    myColor = _color;

    for ( int i = 0; i < 3; i++ )
    {
        std::pair<Vector*, Vector*> edge;

        edge.first = &(points[i]);

        if ( i + 1 < 3 )
            edge.second = &(points[i + 1]);

        else
            edge.second = &(points[0]);

        edges.push_back(edge);
    }
}

bool Triangle::bIntersects(Ray* ray, double* dist)
{
    double unused_;
    double* unused = &unused_;
    Vector cv;

    cv = ray->start;

    ray->dir.add(ray->start);

    return intersect_triangle3(
        &(ray->start.c_array()[0]),
        &(ray->dir.c_array()[0]),
        &(edges[0].first->c_array()[0]),
        &(edges[1].first->c_array()[0]),
        &(edges[2].first->c_array()[0]),
        dist, unused, unused
    ) > 0;
}
