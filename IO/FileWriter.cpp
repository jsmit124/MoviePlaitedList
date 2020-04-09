#include "FileWriter.h"

#include "Utils.h"

namespace io
{

FileWriter::FileWriter()
{
    //ctor
}

bool FileWriter::write(MovieNode* startNode, string outFile)
{
    string output = "";
    MovieNode* currNode = startNode;

    while (currNode != 0)
    {
        Movie* currMovie = currNode->getMovieInfo();
        output += currMovie->getName() + "," + currMovie->getStudio() + "," + to_string(currMovie->getYear()) + "," + ENUM_TO_STR(currMovie->getRating()) + "," + to_string(currMovie->getLength()) + "\n";
        currNode = currNode->getNextName();
    }

    ofstream file(outFile);
    if(file.is_open())
    {
        file << output;
        file.close();
        return true;
    }
    else
    {
        cout << "Cannot open file" << endl;
        return false;
    }
}

FileWriter::~FileWriter()
{
    //dtor
}

}
