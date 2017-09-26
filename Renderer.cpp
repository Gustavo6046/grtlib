#include "Renderer.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include "Vector.h"

using std::vector;
using std::string;
using std::max;
using std::min;

SFMLRenderer::SFMLRenderer(string _title)
{
    title = _title;
}

bool SFMLRenderer::render(int resX, int resY, Vector* colors)
{
    sf::Image im;
    sf::Texture tex;
    vector<sf::Uint8> col;
    col.reserve(resX * resY * 4);

    window.create(sf::VideoMode(resX, resY), title.c_str());

    for ( long i = 0; i < resX * resY; i++ )
    {
        Vector cv = colors[i];

        col[i] = max(min((char) cv.x, '\xFF'), '\x00');
        col[i] = max(min((char) cv.y, '\xFF'), '\x00');
        col[i] = max(min((char) cv.z, '\xFF'), '\x00');
        col[i] = 0xFF;

        i++;
    }

    im.create(resX, resY, &col[0]);

    if ( !tex.loadFromImage(im) )
    {
        window.close();

        return false;
    }

    raytraced = sf::Sprite(tex);

    return true;
}

void SFMLRenderer::drawWindow()
{
    while ( window.isOpen() )
    {
        sf::Event evt;

        while ( window.pollEvent(evt) )
            if ( evt.type == sf::Event::Closed )
                window.close();

        window.clear();
        window.draw(raytraced);
        window.display();
    }
}
