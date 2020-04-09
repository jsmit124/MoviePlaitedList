#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "MoviePlaitedList.h"
#include "Movie.h"
using namespace model;

#include "Formatter/OutputFormatter.h"
using namespace formatter;

#include <string>
using namespace std;

namespace controller {

class Controller
{
    public:
        Controller();
        virtual ~Controller();

        void addToMovieList(Movie movie);
        const string getFormattedOutput();

    protected:

    private:
        MoviePlaitedList movieList;
        OutputFormatter formatter;

};

}

#endif // CONTROLLER_H
