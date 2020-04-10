#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "MovieNode.h"
using namespace model;

#include "SaveFileFormatter.h"
using namespace formatter;

#include <fstream>
#include <string>
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
