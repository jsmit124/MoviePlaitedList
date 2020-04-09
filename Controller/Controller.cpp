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
}

void Controller::addToMovieList(Movie movie)
{
    if (this->movieList.getListSize() == 0)
    {
        this->movieList.addToHead(movie);
    }
    else
    {
        this->movieList.addMovieNodeByName(movie);
    }
}

const string Controller::getFormattedOutput()
{
    return this->formatter.formatMoviesAscendingByName(this->movieList.getHeadNameNode());
}

bool Controller::writeFile(string outFile)
{
    if (this->movieList.getListSize() > 0)
    {
        bool fileWritten = this->fileWriter.write(this->movieList.getHeadNameNode(), outFile);
        if (fileWritten)
        {
            return true;
        }
    }

    return false;
}

Controller::~Controller()
{
    //dtor
}

}
