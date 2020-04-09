#include "Controller.h"

#include "MoviePlaitedList.h"
#include "MovieNode.h"
using namespace model;

#include "Formatter/OutputFormatter.h"
using namespace formatter;

#include <string>
#include <iostream>
using namespace std;

namespace controller
{

Controller::Controller()
{
    this->movieList = MoviePlaitedList();
    this->formatter = OutputFormatter();
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

Controller::~Controller()
{
    //dtor
}

}
