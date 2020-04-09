#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "MoviePlaitedList.h"
#include "MovieNode.h"
#include "Movie.h"
using namespace model;

#include "Formatter/OutputFormatter.h"
using namespace formatter;

#include "IO/FileWriter.h"
using namespace io;

#include <string>
#include <iostream>
using namespace std;

namespace controller {

class Controller
{
    public:
        Controller();
        virtual ~Controller();

        void addToMovieList(Movie movie);
        const string getFormattedOutput();
        bool writeFile(string outFile);

    protected:

    private:
        MoviePlaitedList movieList;
        OutputFormatter formatter;
        FileWriter fileWriter;

};

}

#endif // CONTROLLER_H
