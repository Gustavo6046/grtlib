#ifndef SCENE_H
#define SCENE_H

#include <deque>
#include <map>
#include <vector>
#include <string>
#include "RenderObj.hpp"

using std::deque;
using std::map;
using std::string;
using std::vector;


class Scene
{
    public:
        Scene();
        Scene(deque<RenderObj> objects);
        Scene(vector<RenderObj> objects);

        deque<RenderObj> objects;
        map<string, vector<RenderObj*> > groups;

    protected:
    private:
};

#endif // SCENE_H
