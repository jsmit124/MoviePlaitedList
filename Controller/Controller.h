#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "SortOrder.h"

#include "MoviePlaitedList.h"
#include "MovieNode.h"
#include "Movie.h"
using namespace model;

#include "Formatter/OutputFormatter.h"
using namespace formatter;

#include "IO/FileWriter.h"
#include "IO/FileReader.h"
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
        bool deleteFromMovieList(const string& movieName);
        const string getFormattedOutput(SortOrder);
        bool writeFile(string outFile);
        bool readFile(string inFile);

    protected:

    private:
        MoviePlaitedList movieList;
        OutputFormatter formatter;
        FileWriter fileWriter;
        FileReader fileReader;
};

}

#endif // CONTROLLER_H
