#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Vector.hpp"

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
    bool bDrawDemanded;

    SFMLRenderer(string _title);
    bool render(int resX, int resY, Vector* colors);
    void drawWindow();
    void drawDemanded() { bDrawDemanded = true; }
};

#endif // RENDERER_H
