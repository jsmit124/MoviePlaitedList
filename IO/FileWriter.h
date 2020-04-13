#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "Utils.h"

#include "MovieNode.h"
using namespace model;

#include "SaveFileFormatter.h"
using namespace formatter;

#include <fstream>
#include <string>
using namespace std;

namespace io
{
/*
* Handles implementation of the FileWriter class
*/
class FileWriter
{
public:
    /*
    * Constructs a new FileWriter object
    */
    FileWriter();
    /*
    * Destructs the FileWriter object
    */
    virtual ~FileWriter();

    /*
    * Writes the movie list to a CSV file at the desired file path
    *
    * @precondition outFile !EQUAL null AND outFile !EQUAL .empty()
    * @postcondition none
    *
    * @param outFile
    *       A reference to the string representation of the output file path
    * @param startNode
    *       The node for the method to start iteration from
    *
    * @return
    *       True if the output file is written to; false otherwise
    */
    bool write(MovieNode* startNode, string outFile);
};

}

#endif // FILEWRITER_H
