#include "SaveFileFormatter.h"

namespace formatter
{

SaveFileFormatter::SaveFileFormatter()
{
    //ctor
}

const string SaveFileFormatter::formatMoviesForSave(MovieNode* startNode)
{
    string output;
    string seperator = ",";
    MovieNode* currNode = startNode;

    while (currNode != 0)
    {
        Movie* currMovie = currNode->getMovieInfo();
        output += currMovie->getName() + seperator;
        output += currMovie->getStudio() + seperator;
        output += to_string(currMovie->getYear()) + seperator;
        output += GET_RATING_FROM_INT(currMovie->getRating()) + seperator;
        output += to_string(currMovie->getLength()) + "\n";

        currNode = currNode->getNextName();
    }

    return output;
}

SaveFileFormatter::~SaveFileFormatter()
{
    //dtor
}

}
