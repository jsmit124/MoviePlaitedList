#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "MovieNode.h"
#include "Movie.h"
using namespace model;

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

namespace io
{

class FileWriter
{
    public:
        FileWriter();
        virtual ~FileWriter();

        bool write(MovieNode* startNode, string outFile);

    protected:

    private:
};

}

#endif // FILEWRITER_H
