#include "FileWriter.h"

namespace io
{

FileWriter::FileWriter()
{
    //ctor
}

bool FileWriter::write(MovieNode* startNode, string outFile)
{
    SaveFileFormatter formatter = SaveFileFormatter();
    string output = formatter.formatMoviesForSave(startNode);

    ofstream file(outFile);
    if(file.is_open())
    {
        file << output;
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}

FileWriter::~FileWriter()
{
    //dtor
}

}
