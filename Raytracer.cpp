#include "Raytracer.hpp"
#include "Renderer.hpp"
#include "Raymath.hpp"
#include <iostream>

#include <vector>

using std::vector;

void Raytracer::renderFor(Camera* camera, Renderer* renderer)
{
    std::vector<Vector> colors;

    int oind;
    int loind;

    for ( double rx = 0; rx < resolution[0]; rx++ )
        for ( double ry = 0; ry < resolution[1]; ry++ )
        {
            double x = rx / resolution[0] - 0.5;
            double y = ry / resolution[1] - 0.5;

            Ray ray = dcamlerp(camera, x, y);

            int oind = 0;

            Vector lastColor;
            double distance, minDist;
            bool bCollided;

            for ( RenderObj tri : scene->objects )
            {
                if ( ( rx == 0 || rx == resolution[0]-1 ) && ( ry == 0 || ry == resolution[1]-1 ) )
                    std::cout << x << " " << y << " -> " << ray.dir.repr() << " ,aim" << oind << "= " << (ray.dir.towardness(tri.center() - ray.start)) << "\n";

                oind++;

                if ( tri.bIntersects(&ray, &distance) && distance < minDist )
                {
                    minDist = distance;
                    lastColor = tri.myColor;
                    lastColor.mul(1.0 - distance / 256.0);
                    bCollided = true;
                    loind = oind;
                }
            }

            if ( !bCollided )
                lastColor = Vector(0, 0, 0);

            /*
            if ( bCollided )
                std::cout << "Intersection found at ray " << ray.start.repr() << " dir " << ray.dir.repr() << " with object " << loind << ", resulting in color" << lastColor.repr(new char[3]{'r', 'g', 'b'}) << "\n";

            else
                std::cout << "No intersection found at ray " << ray.start.repr() << " dir " << ray.dir.repr() << ", resulting in color" << lastColor.repr(new char[3]{'r', 'g', 'b'}) << "\n";
            */

            colors.push_back(lastColor);
        }

    std::cout << "\n";

    renderer->render(resolution[0], resolution[1], &colors[0]);
}
