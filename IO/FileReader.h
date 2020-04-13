#ifndef FILEREADER_H
#define FILEREADER_H

#include "Enum/MovieRating.h"

#include "Movie.h"
using namespace model;

#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

namespace io
{
/*
* Handles implementation of the FileReader class
*/
class FileReader
{
public:
    /*
    * Constructs a new FileReader object
    */
    FileReader();
    /*
    * Destructs the FileReader object
    */
    virtual ~FileReader();

    /*
    * Reads the movie list from the file at inFile
    *
    * @precondition none
    * @postcondition none
    *
    * @param inFile
    *       The path to the file to read from
    *
    * @return output
    *       The vector of movie objects found in the file.0
    */
    vector<Movie*> read(const string& inFile);
};

}

#endif // FILEREADER_H
