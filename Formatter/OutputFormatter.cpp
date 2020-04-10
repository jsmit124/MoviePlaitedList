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

const string OutputFormatter::formatMoviesAscendingByName(MovieNode* startNode, int longestNameLength, int longestStudioLength)
{
    string output;

    if (startNode == 0)
    {
        return "";
    }

    output += this->formatMovieLineOutput(startNode, longestNameLength, longestStudioLength);
    output += this->formatMoviesAscendingByName(startNode->getNextName(), longestNameLength, longestStudioLength);

    return output;
}

const string OutputFormatter::formatMoviesDecendingByName(MovieNode* startNode, int longestNameLength, int longestStudioLength)
{
    string output;

    if (startNode == 0)
    {
        return "";
    }

    output += this->formatMoviesDecendingByName(startNode->getNextName(), longestNameLength, longestStudioLength);
    output += this->formatMovieLineOutput(startNode, longestNameLength, longestStudioLength);

    return output;
}

const string OutputFormatter::formatMoviesAscendingByLength(MovieNode* startNode, int longestNameLength, int longestStudioLength)
{
    string output;

    if (startNode == 0)
    {
        return "";
    }

    output += this->formatMovieLineOutput(startNode, longestNameLength, longestStudioLength);
    output += this->formatMoviesAscendingByLength(startNode->getNextLength(), longestNameLength, longestStudioLength);

    return output;
}

const string OutputFormatter::formatMoviesDecendingByLength(MovieNode* startNode, int longestNameLength, int longestStudioLength)
{
    string output;

    if (startNode == 0)
    {
        return "";
    }

    output += this->formatMoviesDecendingByLength(startNode->getNextLength(), longestNameLength, longestStudioLength);
    output += this->formatMovieLineOutput(startNode, longestNameLength, longestStudioLength);

    return output;
}

const string OutputFormatter::formatMoviesAscendingByRating(MovieNode* startNode, int longestNameLength, int longestStudioLength)
{

}

const string OutputFormatter::formatMoviesDecendingByRating(MovieNode* startNode, int longestNameLength, int longestStudioLength)
{

}

const string OutputFormatter::formatMovieLineOutput(MovieNode* startNode, int longestNameLength, int longestStudioLength)
{
    string output;

    string name = startNode->getMovieInfo()->getName();
    string studio = startNode->getMovieInfo()->getStudio();
    int length = startNode->getMovieInfo()->getLength();
    int year = startNode->getMovieInfo()->getYear();

    MovieRating rating = startNode->getMovieInfo()->getRating();
    string ratingValue = GET_RATING_STRING(rating);

    string nameAndYear = name + "-" + to_string(year);
    nameAndYear.resize(longestNameLength + to_string(year).size() + 2, ' ');
    output += nameAndYear;

    studio.resize(longestStudioLength + 1, ' ');
    output += studio;

    ratingValue.resize(5, ' ');
    output += ratingValue;

    output += to_string(length) + "\n";

    return output;
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

}
