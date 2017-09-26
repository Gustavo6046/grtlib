#ifndef LINE_H
#define LINE_H

#include "Vector.hpp"

using std::pair;

class Line
{
    public:
        /** Default constructor */
        Line(pair<Vector*, Vector*> sides);

        pair<Vector*, Vector*> sides; //!< Member variable "sides"

    protected:
    private:
};

#endif // LINE_H
