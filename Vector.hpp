#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <cmath>
#include <sstream>

using std::stringstream;
using std::max;


class Vector
{
    public:
        /** Default constructor */
        Vector(double x, double y, double z);

        // credits to Rosetta Code
        Vector cross ( Vector& rhs ) {
            double a = y * rhs.z - z * rhs.y ;
            double b = z * rhs.x - x * rhs.z ;
            double c = x * rhs.y - y * rhs.x ;

            Vector product(a, b, c);
            return product;
        }

        std::string repr()
        {
            stringstream composition;

            composition << "x=" << x << ",y=" << y << ",z=" << z;

            return composition.str();
        }

        std::string repr(char labels[3])
        {
            stringstream composition;

            composition << labels[0] << "=" << x << "," << labels[1] << "=" << y << "," << labels[2] << "=" << z;

            return composition.str();
        }

        Vector();

        Vector* add(Vector other)
        {
            x += other.x;
            y += other.y;
            z += other.z;

            return this;
        }

        Vector* sub(Vector other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;

            return this;
        }

        Vector* mul(double a)
        {
            x *= a;
            y *= a;
            z *= a;

            return this;
        }

        Vector* mul(Vector other)
        {
            x *= other.x;
            y *= other.y;
            z *= other.z;

            return this;
        }

        Vector* div(double a)
        {
            x /= a;
            y /= a;
            z /= a;

            return this;
        }

        Vector* div(Vector other)
        {
            x /= other.x;
            y /= other.y;
            z /= other.z;

            return this;
        }

        double len()
        {
            return sqrt(sqlen());
        }

        double sqlen()
        {
            return fabs(pow(x, 2) + pow(y, 2) + pow(z, 2));
        }

        Vector norm()
        {
            Vector na = *this;

            return *(na.div(na.len()));
        }

        static Vector* mean(std::vector<Vector> vectors)
        {
            Vector m;

            for ( Vector v : vectors )
            {
                m.add(v);
            }

            return m.div(vectors.size());
        }

        double* c_array()
        {
            return new double[3]{x, y, z};
        }

        double sum()
        {
            return x + y + z;
        }

        double towardness(Vector other)
        {
            Vector nv = *this;

            return nv.norm().dot(other.norm());
        }

        double dot(Vector other)
        {
            Vector a = other;

            return a.mul(*this)->sum();
        }

        double x; //!< Member variable "x"
        double y; //!< Member variable "y"
        double z; //!< Member variable "z"

    protected:
    private:
};

bool operator== (Vector a, Vector b);
bool operator!= (Vector a, Vector b);
double operator^ (Vector a, Vector b); // dot product
Vector operator- (Vector a, Vector b);
Vector operator+ (Vector a, Vector b);
Vector operator* (Vector a, Vector b);
Vector operator/ (Vector a, Vector b);
Vector operator* (Vector a, double b);
Vector operator/ (Vector a, double b);
Vector operator! (Vector a); // vector normal
double operator~ (Vector a); // vector length

#endif // VERTEX_H
