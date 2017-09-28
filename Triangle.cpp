#include "Triangle.hpp"
#include "Raymath.hpp"
#include "Camera.hpp"

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
    Vector rayOrigin = ray->start;
    Vector rayVector = !(ray->dir);

    const float EPSILON = 0.0000001;

    Vector vertex0 = *(this->edges[0].first);
    Vector vertex1 = *(this->edges[1].first);
    Vector vertex2 = *(this->edges[2].first);
    Vector edge1, edge2, h, s, q;

    float a,f,u,v;

    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    h = rayVector.cross(edge2);
    a = edge1 ^ h;

    if (a > -EPSILON && a < EPSILON)
        return false;

    f = 1/a;
    s = rayOrigin - vertex0;
    u = f * (s.dot(h));

    if (u < 0.0 || u > 1.0)
        return false;

    q = s.cross(edge1);
    v = f * rayVector.dot(q);

    if (v < 0.0 || u + v > 1.0)
        return false;

    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * edge2.dot(q);

    if (t > EPSILON) // ray intersection
    {
        *dist = ~((!rayVector) * (t * rayVector.len()));
        return true;
    }

    else // This means that there is a line intersection but not a ray intersection.
        return false;
}

Vector Triangle::center()
{
    Vector vertexes[3] = {
        *edges[0].first,
        *edges[1].first,
        *edges[2].first
    };

    Vector res;

    for ( Vector v : vertexes )
        res = res + v;

    return res / 3;
}
