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

    string name = startNode->getMovieInfo()->getName();
    string studio = startNode->getMovieInfo()->getStudio();
    int length = startNode->getMovieInfo()->getLength();
    int year = startNode->getMovieInfo()->getYear();
    Movie::Rating rating = startNode->getMovieInfo()->getRating();

    output += name + " | ";
    output += to_string(year) + " | ";
    output += studio + " | ";
    output += rating + " | ";
    output += to_string(length) + " minutes\n";

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

    string name = startNode->getMovieInfo()->getName();
    string studio = startNode->getMovieInfo()->getStudio();
    int length = startNode->getMovieInfo()->getLength();
    int year = startNode->getMovieInfo()->getYear();
    Movie::Rating rating = startNode->getMovieInfo()->getRating();

    output += name + " | ";
    output += to_string(year) + " | ";
    output += studio + " | ";
    output += rating + " | ";
    output += to_string(length) + " minutes\n";

    return output;
}

const string OutputFormatter::formatMoviesAscendingByLength(MovieNode* startNode)
{
    string output;

    if (startNode == 0)
    {
        return "";
    }

    string name = startNode->getMovieInfo()->getName();
    string studio = startNode->getMovieInfo()->getStudio();
    int length = startNode->getMovieInfo()->getLength();
    int year = startNode->getMovieInfo()->getYear();
    Movie::Rating rating = startNode->getMovieInfo()->getRating();

    output += name + " | ";
    output += to_string(year) + " | ";
    output += studio + " | ";
    output += rating + " | ";
    output += to_string(length) + " minutes\n";

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

    string name = startNode->getMovieInfo()->getName();
    string studio = startNode->getMovieInfo()->getStudio();
    int length = startNode->getMovieInfo()->getLength();
    int year = startNode->getMovieInfo()->getYear();
    Movie::Rating rating = startNode->getMovieInfo()->getRating();

    output += name + " | ";
    output += to_string(year) + " | ";
    output += studio + " | ";
    output += rating + " | ";
    output += to_string(length) + " minutes\n";

    return output;
}

const string OutputFormatter::formatMoviesAscendingByRating(MovieNode* startNode)
{

}

const string OutputFormatter::formatMoviesDecendingByRating(MovieNode* startNode)
{

}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

}
