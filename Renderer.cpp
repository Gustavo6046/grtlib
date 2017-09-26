#include "Renderer.hpp"

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include <memory>
#include "Vector.hpp"

using std::vector;
using std::string;
using std::max;
using std::min;
using std::find;
using std::unique_ptr;


SFMLRenderer::SFMLRenderer(string _title)
{
    title = _title;
}

bool SFMLRenderer::render(int resX, int resY, Vector* colors)
{
    sf::Image im;
    unique_ptr<sf::Texture> tex(new sf::Texture());
    vector<sf::Uint8> col;
    col.reserve(resX * resY * 4);

    vector<Vector> knownColors;
    knownColors.reserve(resX * resY);

    for ( long i = 0; i < resX * resY; i++ )
    {
        Vector cv = colors[i];

        while (true) // not forever
        {
            bool bFound = false;

            for ( Vector comp : knownColors )
                if ( comp == cv )
                    bFound = true;

            if ( bFound )
                break;

            knownColors.push_back(cv);
            // std::cout << cv.repr(new char[3]{'r', 'g', 'b'}) << " ";

            break;
        }

        col[i * 4] = max(min((char) cv.x, '\xFF'), '\x00');
        col[i * 4 + 1] = max(min((char) cv.y, '\xFF'), '\x00');
        col[i * 4 + 2] = max(min((char) cv.z, '\xFF'), '\x00');
        col[i * 4 + 3] = 0xFF;

        i++;
    }

    std::cout << "Done counting colors: " << knownColors.size() << "\n";

    im.create(resX, resY, &col[0]);

    if ( !tex->loadFromImage(im) )
    {
        window.close();

        return false;
    }

    raytraced = sf::Sprite(*tex);

    bDrawDemanded = true;

    window.create(sf::VideoMode(resX, resY), title.c_str()); // drawWindow() should be called right after for maximum performance.

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

        if ( bDrawDemanded )
        {
            window.clear();
            // window.draw(raytraced);
        }

        window.display();

        bDrawDemanded = false;
    }
}
