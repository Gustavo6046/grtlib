/**
 * grtlib
 * ©2017 Gustavo Ramos "Gustavo6046" Rehermann.
 * MIT license.
 *
 * This program was created as a hackable experiment.
 */

#include "Raytracer.h"
#include "Renderer.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Scene.h"
#include "Camera.h"


int main(int argc, char* argv[])
{
    Camera cam;
    Scene ctx;

    int resolution[2] = {640, 400};

    SFMLRenderer renderer("grtlib Test");
    Raytracer tracer(resolution, &ctx);

    ctx.objects.push_back(Triangle(new Vector[3] {Vector(-1024, 0, -16), Vector(0, 1024, -16), Vector(1024, 0, -16)}, Vector(255, 0, 0)));
    ctx.objects.push_back(Sphere(Vector(512, 0, 512), 512, Vector(0, 0, 255)));

    cam.fov = 90;
    cam.position = Vector(512, -768, 512);
    cam.rotation = !Vector(0, 3, -1);

    tracer.renderFor(&cam, &renderer);

    renderer.drawWindow();
}
