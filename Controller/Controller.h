#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "MoviePlaitedList.h"
#include "Movie.h"
using namespace model;

namespace controller {

class Controller
{
    public:
        Controller();
        virtual ~Controller();

        void addToMovieList(Movie movie);

    protected:

    private:
        MoviePlaitedList movieList;
};

}

#endif // CONTROLLER_H
