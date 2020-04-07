#include "Controller.h"

#include "MoviePlaitedList.h"
#include "MovieNode.h"
using namespace model;

namespace controller
{

Controller::Controller()
{
    //ctor
}

void Controller::addToMovieList(Movie movie)
{
    if (this->movieList.getListSize() == 0)
    {
        auto movieNode = MovieNode(&movie, nullptr, nullptr, nullptr);
        this->movieList = MoviePlaitedList(movieNode);
    }
    else
    {
        auto movieNode = MovieNode(&movie, nullptr, nullptr, nullptr); //TODO
        this->movieList.addMovieNode(movieNode);
    }
}

Controller::~Controller()
{
    //dtor
}

}
