#include "FileReader.h"

#include <iostream>
#include <sstream>
using namespace std;

namespace io
{

FileReader::FileReader()
{
    //ctor
}

vector<Movie*> FileReader::read(const string& inFile)
{
    ifstream fileStream;
    vector<string> row;
    vector<Movie*> output;
    string line, entry;

    fileStream.open(inFile);

    if (fileStream.is_open())
    {
        while (getline(fileStream, line))
        {
            row.clear();

            cout << line << endl;
            stringstream stringStream(line);
            while (getline(stringStream, entry, ','))
            {
                row.push_back(entry);
            }
            try
            {
                string name = row[0];
                string studio = row[1];
                int year = stoi(row[2]);
                string ratingEntered = row[3];

                MovieRating rating = MovieRating::NOT_RATED;

                if (ratingEntered == ENUM_TO_STR(G))
                {
                    rating = MovieRating::G;
                }
                else if (ratingEntered == ENUM_TO_STR(PG))
                {
                    rating = MovieRating::PG;
                }
                else if (ratingEntered == ENUM_TO_STR(PG13))
                {
                    rating = MovieRating::PG13;
                }
                else if (ratingEntered == ENUM_TO_STR(R))
                {
                    rating = MovieRating::R;
                }

                int length = stoi(row[4]);

                Movie* pMovie = new Movie(name, studio, year, rating, length);
                output.push_back(pMovie);
            }
            catch (const std::exception& e)
            {
                continue;
            }
        }
    }
    return output;
}

FileReader::~FileReader()
{
    //dtor
}

}
