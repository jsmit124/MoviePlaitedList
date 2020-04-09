#ifndef FILEREADER_H
#define FILEREADER_H

#include "Movie.h"
using namespace model;

#include <vector>
#include <fstream>
using namespace std;

namespace io
{

class FileReader
{
    public:
        FileReader();
        virtual ~FileReader();

        vector<Movie*> read(const string& inFile);

    protected:

    private:
};

}

#endif // FILEREADER_H
