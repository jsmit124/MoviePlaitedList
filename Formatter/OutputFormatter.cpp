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
//TODO make this recursive
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
        output += studio + " | ";

        cout << (Movie::Rating)rating << endl;

        output += currMoviePtr->getRating() + " | ";
        output += to_string(length) + " minutes\n";

        currNodePtr = currNodePtr->getNextName();
    }

    return output;
}

const string formatMoviesDecendingByName(MovieNode* startNode);
{

}

const string formatMoviesAscendingByLength(MovieNode* startNode)
{

}

const string formatMoviesDecendingByLength(MovieNode* startNode)
{

}

const string formatMoviesAscendingByRating(MovieNode* startNode)
{

}

const string formatMoviesDecendingByRating(MovieNode* startNode)
{

}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

}
