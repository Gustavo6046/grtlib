#include "Raytracer.h"
#include "Renderer.h"
#include "Raymath.h"

#include <vector>

using std::vector;

void Raytracer::renderFor(Camera* camera, Renderer* renderer)
{
    std::vector<Vector> colors;

    for ( double x = -0.5d; x < 0.5d; x += (1.0d / (double) (resolution[0])) )
        for ( double y = -0.5d; y < 0.5d; y += (1.0d / (double) (resolution[1])) )
        {
            Ray ray = camlerp(camera, x, y);
            Vector lastColor;
            double distance, minDist;

            for ( RenderObj tri : scene->objects )
                if ( tri.bIntersects(&ray, &distance) && distance < minDist )
                {
                    minDist = distance;
                    lastColor = tri.myColor;
                    lastColor.mul(1.0 - distance / 256.0);
                }

            colors.push_back(lastColor);
        }

    if ( renderer != NULL )
        renderer->render(resolution[0], resolution[1], colors.data());
}
