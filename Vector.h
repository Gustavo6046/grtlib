#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <cmath>

using std::max;


class Vector
{
    public:
        /** Default constructor */
        Vector(double x, double y, double z);

        /** Access x
         * \return The current value of x
         */
        double Getx() { return x; }
        /** Set x
         * \param val New value to set
         */
        void Setx(double val) { x = val; }
        /** Access y
         * \return The current value of y
         */
        double Gety() { return y; }
        /** Set y
         * \param val New value to set
         */
        void Sety(double val) { y = val; }
        /** Access z
         * \return The current value of z
         */
        double Getz() { return z; }
        /** Set z
         * \param val New value to set
         */
        void Setz(double val) { z = val; }

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
            double v = max(max(x, y), z);

            return Vector(x / v, y / v, z / v);
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

Vector operator- (Vector a, Vector b);
Vector operator+ (Vector a, Vector b);
Vector operator* (Vector a, Vector b);
Vector operator/ (Vector a, Vector b);
Vector operator! (Vector a);

#endif // VERTEX_H
