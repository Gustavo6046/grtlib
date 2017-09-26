#include "Camera.hpp"
#include "Vector.hpp"
#include "Raymath.hpp"

#include <cmath>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286


/** \brief Linear interpolation.
 * Interpolates between two values,
 * using f as the value used to
 * transform 0->1 to a->b, and
 * returns the transformed value.
 *
 * \param a The least value.
 * \param b The largest value.
 * \param f The mapped value (between 0 and 1).
 * \return The transformed value.
 *
 */

double lerp(double a, double b, double f)
{
    return (a * (1.0 - f)) + (b * f);
}

/** \brief Tangent for FOV calculations.
 * This function calculates the tangent,
 * which is one of the most used
 * trigonometrical functions used during
 * ray forming.
 *
 * \param fov Field of View value, in radians.
 * \param i Step distance.
 * \return The tangent (used for FOV calculations).
 *
 */

double fovtan(double fov, double i)
{
    return i * tan(fov);
}

/** \brief Tangent for FOV calculations (in degrees).
 * This function calculates the tangent,
 * which is one of the most used
 * trigonometrical functions used during
 * ray forming.
 *
 * This is however a degree-based variant,
 * designed for FOV values determined by
 * user input.
 *
 * \param fov Field of View value, in degrees.
 * \param i Ray distance.
 * \return The tangent (used for FOV calculations).
 *
 */
double dfovtan(double fov, double i)
{
    return i * tan(fov * 180 / PI);
}

/** \brief Converts polar coordinates/angles to Cartesian ones.
 *
 * \param pitch The pitch angle component.
 * \param yaw The yaw angle component.
 * \return The relative vector.
 *
 */
Vector fromPolar(double pitch, double yaw)
{
    Vector res;

    res.x = -cos(yaw) * cos(pitch);
    res.y = sin(yaw) * cos(pitch);
    res.z = -sin(pitch);

    return res;
}

/** \brief Linear interpolation for camera ray formation.
 *
 * \param stepX The X step, from 0 to 1.
 * \param stepY The Y step, from 0 to 1.
 * \return The final interpolation.
 *
 */
Ray camlerp(Camera* cam, double stepX, double stepY)
{
    double a = -fovtan(cam->fov, 1.0);
    double b = -a;

    Ray res;

    res.start = cam->position;
    res.dir = fromPolar(lerp(a, b, stepX), lerp(a, b, stepY));

    return res;
}

Ray dcamlerp(Camera* cam, double stepX, double stepY)
{
    double a = -dfovtan(cam->fov, 1.0);
    double b = -a;

    Ray res;

    res.start = cam->position;
    res.dir = fromPolar(lerp(a, b, stepX), lerp(a, b, stepY));

    return res;
}
