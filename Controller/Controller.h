#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Enum/SortOrder.h"

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

namespace controller
{
/*
* Handles functionality for the Controller class
*/
class Controller
{
public:
    /*
    * Constructs a new Controller object
    */
    Controller();
    /*
    * Destructs a Controller object
    */
    virtual ~Controller();

    /*
    * Mitigates adding a movie object to the movie list
    *
    * @precondition none
    * @postcondition this->movieList.listSize += 1
    *               AND movie added to this->movieList
    *
    * @param movie
    *       The movie object to add
    *
    * @return void
    */
    void addToMovieList(Movie);
    /*
    * Mitigates deleting a movie object from the movie list
    *
    * @precondition none
    * @postcondition this->movieList.listSize -= 1
    *               AND movie deleted from this->movieList
    *
    * @param movieName
    *       The movie object's name to delete
    *
    * @return true if object is deleted from the list;
    *         false otherwise
    */
    bool deleteFromMovieList(const string&);
    /*
    * Mitigates the formatting of the movie output
    *
    * @precondition none
    * @postcondition none
    *
    * @param sortOrder
    *       The order to sort the output
    *
    * @return output
    *       The formatted output string
    */
    const string getFormattedOutput(SortOrder);
    /*
    * Mitigates writing the movie objects to a CSV file
    *
    * @precondition none
    * @postcondition this->movieList written to desired file
    *
    * @param outFile
    *       The file path to save the movies to
    *
    * @return true if the file is written
    *         false otherwise
    */
    bool writeFile(string);
    /*
    * Mitigates reading the movie objects from a CSV file
    *
    * @precondition none
    * @postcondition this->movieList read from desired file
    *
    * @param inFile
    *       The file path to read the movies from
    *
    * @return true if the file is read
    *         false otherwise
    */
    bool readFile(string);

private:
    MoviePlaitedList movieList;
    OutputFormatter formatter;
    FileWriter fileWriter;
    FileReader fileReader;
};

}

#endif // CONTROLLER_H
