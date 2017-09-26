#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Scene.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"

class Raytracer
{
    public:
        /** Default constructor */
        Raytracer(int _resolution[2], Scene* _scene)
        {
            resolution[0] = _resolution[0];
            resolution[1] = _resolution[1];
            scene = _scene;
        };

        // Members
        Scene* scene;
        int resolution[2];
        string title;
        void renderFor(Camera* camera, Renderer* renderer);

    protected:
    private:
};

#endif // RAYTRACER_H
