#include "Controller.h"

#include "Formatter/OutputFormatter.h"
using namespace formatter;

namespace controller
{

Controller::Controller()
{
    this->movieList = MoviePlaitedList();
    this->formatter = OutputFormatter();
    this->fileWriter = FileWriter();
    this->fileReader = FileReader();
}

void Controller::addToMovieList(Movie movie)
{
    if (this->movieList.getListSize() == 0)
    {
        this->movieList.makeNewList(movie);
    }
    else
    {
        this->movieList.addMovieNode(movie);
    }
}

bool Controller::deleteFromMovieList(const string& movieName)
{
    return this->movieList.deleteMovieNodeByName(movieName);
}

const string Controller::getFormattedOutput(SortOrder order)
{
    int longestNameLength = this->movieList.getLongestNameLength();
    int longestStudioLength = this->movieList.getLongestStudioLength();

    string output;

    if (order == SortOrder::LENGTH_ASCENDING)
    {
        output = formatter.formatMoviesAscendingByLength(this->movieList.getHeadLengthNode(), longestNameLength, longestStudioLength);
    }
    else if (order == SortOrder::LENGTH_DESCENDING)
    {
        output = formatter.formatMoviesDecendingByLength(this->movieList.getHeadLengthNode(), longestNameLength, longestStudioLength);
    }
    else if (order == SortOrder::RATING_ASCENDING)
    {
        output = formatter.formatMoviesAscendingByRating(this->movieList.getHeadRatingNode(), longestNameLength, longestStudioLength);
    }
    else if (order == SortOrder::RATING_DESCENDING)
    {
        output = formatter.formatMoviesDecendingByRating(this->movieList.getHeadRatingNode(), longestNameLength, longestStudioLength);
    }
    else if (order == SortOrder::NAME_DESCENDING)
    {
        output = formatter.formatMoviesDecendingByName(this->movieList.getHeadNameNode(), longestNameLength, longestStudioLength);
    }
    else
    {
        output = formatter.formatMoviesAscendingByName(this->movieList.getHeadNameNode(), longestNameLength, longestStudioLength);
    }

    return output;
}

bool Controller::writeFile(string outFile)
{
    return this->fileWriter.write(this->movieList.getHeadNameNode(), outFile);
}

bool Controller::readFile(string inFile)
{
    vector<Movie*> fileContents = this->fileReader.read(inFile);

    if (fileContents.size() == 0)
    {
        return false;
    }

    for (Movie* currMovie : fileContents)
    {
        this->addToMovieList(*currMovie);
    }
    return true;
}

Controller::~Controller()
{
    //dtor
}

}
