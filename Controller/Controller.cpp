#include "Controller.h"

#include "MoviePlaitedList.h"
#include "MovieNode.h"
using namespace model;

namespace controller
{

Controller::Controller()
{
    this->movieList = MoviePlaitedList();
}

void Controller::addToMovieList(Movie movie)
{
    if (this->movieList.getListSize() == 0)
    {
        this->movieList.addToHead(movie);
    }
    else
    {
        this->movieList.addMovieNode(movie);
    }
}

Controller::~Controller()
{
    //dtor
}

}
