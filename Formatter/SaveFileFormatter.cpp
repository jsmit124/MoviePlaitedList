#include "SaveFileFormatter.h"

namespace formatter
{

SaveFileFormatter::SaveFileFormatter()
{
    //ctor
}

const string SaveFileFormatter::formatMoviesForSave(MovieNode* startNode)
{
    string output = "";
    MovieNode* currNode = startNode;

    while (currNode != 0)
    {
        Movie* currMovie = currNode->getMovieInfo();
        output += currMovie->getName() + "," + currMovie->getStudio() + "," + to_string(currMovie->getYear()) + "," + ENUM_TO_STR(currMovie->getRating()) + "," + to_string(currMovie->getLength()) + "\n";
        currNode = currNode->getNextName();
    }

    return output;
}

SaveFileFormatter::~SaveFileFormatter()
{
    //dtor
}

}
