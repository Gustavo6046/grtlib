#include <sstream>
#include <string>
using std::stringstream;
using std::string;

template<class T>
T assert(string name, T compared, T comparison)
{
    stringstream failString;

    failString << "Fail when testing: " << name << " (" << compared << ")";

    if ( compared != comparison )
        throw failString.str();

    else
        return compared;
}
