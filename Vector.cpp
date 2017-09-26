#include <iostream>

#include "Vector.hpp"

Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}



bool operator== (Vector a, Vector b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!= (Vector a, Vector b)
{
    return !(a == b);
}

double operator^ (Vector a, Vector b) // dot product
{
    return a.dot(b);
}

Vector operator- (Vector a, Vector b)
{
    Vector na = a;

    return *(na.sub(b));
}

Vector operator+ (Vector a, Vector b)
{
    Vector na = a;

    return *(na.add(b));
}

Vector operator* (Vector a, Vector b)
{
    Vector na = a;

    return *(na.mul(b));
}

Vector operator/ (Vector a, Vector b)
{
    Vector na = a;

    return *(na.div(b));
}

Vector operator* (Vector a, double b)
{
    Vector na = a;

    return *(na.mul(b));
}

Vector operator/ (Vector a, double b)
{
    Vector na = a;

    return *(na.div(b));
}

Vector operator! (Vector a)
{
    return a.norm();
}

double operator~ (Vector a)
{
    return a.len();
}
