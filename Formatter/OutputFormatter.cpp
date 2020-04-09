#include "OutputFormatter.h"

#include "Utils.h"

#include <iostream>
using namespace std;

namespace formatter
{

OutputFormatter::OutputFormatter()
{
    //ctor
}

const string OutputFormatter::formatMoviesAscendingByName(MovieNode* startNode)
{
    string output = "";
    MovieNode* currNodePtr = startNode;

    while (currNodePtr != 0)
    {
        Movie* currMoviePtr = currNodePtr->getMovieInfo();

        string name = currMoviePtr->getName();
        string studio = currMoviePtr->getStudio();
        int length = currMoviePtr->getLength();
        int year = currMoviePtr->getYear();
        Movie::Rating rating = currMoviePtr->getRating();

        output += name + " | ";
        output += to_string(year) + " | ";
        output += currMoviePtr->getStudio() + " | ";

        cout << (Movie::Rating)currMoviePtr->getRating() << endl;

        output += currMoviePtr->getRating() + " | ";
        output += to_string(currMoviePtr->getLength()) + " minutes\n";

        currNodePtr = currNodePtr->getNextName();
    }

    return output;
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

}
