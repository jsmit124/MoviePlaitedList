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
    string output;

    if (startNode == 0)
    {
        return "";
    }

    output += this->formatMovieLineOutput(startNode);
    output += this->formatMoviesAscendingByName(startNode->getNextName());

    return output;
}

const string OutputFormatter::formatMoviesDecendingByName(MovieNode* startNode)
{
    string output;

    if (startNode == 0)
    {
        return "";
    }

    output += this->formatMoviesDecendingByName(startNode->getNextName());
    output += this->formatMovieLineOutput(startNode);

    return output;
}

const string OutputFormatter::formatMoviesAscendingByLength(MovieNode* startNode)
{
    string output;

    if (startNode == 0)
    {
        return "";
    }

    output += this->formatMovieLineOutput(startNode);
    output += this->formatMoviesAscendingByLength(startNode->getNextLength());

    return output;
}

const string OutputFormatter::formatMoviesDecendingByLength(MovieNode* startNode)
{
    string output;

    if (startNode == 0)
    {
        return "";
    }

    output += this->formatMoviesDecendingByLength(startNode->getNextLength());
    output += this->formatMovieLineOutput(startNode);

    return output;
}

const string OutputFormatter::formatMoviesAscendingByRating(MovieNode* startNode)
{

}

const string OutputFormatter::formatMoviesDecendingByRating(MovieNode* startNode)
{

}

const string OutputFormatter::formatMovieLineOutput(MovieNode* startNode)
{
    string output;

    string name = startNode->getMovieInfo()->getName();
    string studio = startNode->getMovieInfo()->getStudio();
    int length = startNode->getMovieInfo()->getLength();
    int year = startNode->getMovieInfo()->getYear();

    MovieRating rating = startNode->getMovieInfo()->getRating();
    string ratingValue = getRatingString(rating);

    output += name + "-";
    output += to_string(year) + " | ";
    output += studio + " | ";
    output += ratingValue + " | ";
    output += to_string(length) + " minutes\n";

    return output;
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

}
