#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Vector.h"

using std::vector;
using std::string;


class Renderer
{
public:
    virtual bool render(int resX, int resY, Vector* colors) = 0;
    virtual void drawWindow() = 0;

protected:
private:
};

class SFMLRenderer: public Renderer
{
public:
    sf::RenderWindow window;
    sf::Sprite raytraced;
    string title;

    SFMLRenderer(string _title);
    bool render(int resX, int resY, Vector* colors);
    void drawWindow();
};

#endif // RENDERER_H
