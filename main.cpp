/**
 * grtlib
 * ©2017 Gustavo Ramos "Gustavo6046" Rehermann.
 * MIT license.
 *
 * This program was created as a hackable experiment.
 */

#include "Raytracer.hpp"
#include "Renderer.hpp"
#include "Triangle.hpp"
#include "Sphere.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "assertion.cpp"
#include <iostream>


int main(int argc, char* argv[])
{
    Ray testRay;
    Vector zeroVec;
    double dist;

    testRay.start = Vector(0, -4, 0);
    testRay.dir = Vector(0, 1, 0);

    try
    {
        assert<bool>("Sphere Intersection #1", (new Sphere(zeroVec, 2, zeroVec))->bIntersects(&testRay, &dist), true);
        assert<bool>("Sphere Intersection #2", (new Sphere(*(new Vector(0, 0, 4.5)), 2, zeroVec))->bIntersects(&testRay, &dist), false);
        assert<bool>("Triangle Intersection #1", (new Triangle(new Vector[3]{*(new Vector(-4, 0, -4)), *(new Vector(0, 0, 4)), *(new Vector(4, 0, -4))}, zeroVec))->bIntersects(&testRay, &dist), true);
    }

    catch (string err)
    {
        std::cout << err << "\n";
        throw err;
    }

    Camera cam;
    Scene ctx;

    int resolution[2] = {640, 400};

    SFMLRenderer renderer("grtlib Test");
    Raytracer tracer(resolution, &ctx);

    ctx.objects.push_back(Triangle(new Vector[3] {Vector(-1024, 0, -16), Vector(0, 1024, -16), Vector(1024, 0, -16)}, Vector(255, 0, 0)));
    ctx.objects.push_back(Sphere(Vector(512, 0, 512), 512, Vector(0, 0, 255)));

    cam.fov = 90    ;
    cam.position = Vector(512, -768, 512);
    cam.rotation = !Vector(0, 1, 0);

    tracer.renderFor(&cam, &renderer);

    renderer.drawWindow();
}
