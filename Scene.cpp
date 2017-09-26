#include "Scene.hpp"

#include <deque>

using std::deque;

Scene::Scene(deque<RenderObj> objects)
{
    this->objects = objects;
}

Scene::Scene(vector<RenderObj> objects)
{
    for ( RenderObj t : objects )
        this->objects.push_back(t);
}

Scene::Scene() {}
