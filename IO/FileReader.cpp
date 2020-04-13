#include "FileReader.h"

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

            stringstream stringStream(line);
            while (getline(stringStream, entry, ','))
            {
                row.push_back(entry);
            }
            try
            {
                string name = row[NAME_INDEX];
                string studio = row[STUDIO_INDEX];
                int year = stoi(row[YEAR_INDEX]);
                string ratingEntered = row[RATING_INDEX];
                MovieRating rating = GET_RATING_FROM_STRING(ratingEntered);
                int length = stoi(row[LENGTH_INDEX]);

                if (this->validateMovieValues(name, studio, year, rating, length))
                {
                    Movie* pMovie = new Movie(name, studio, year, rating, length);
                    output.push_back(pMovie);
                }
            }
            catch (const std::exception& e)
            {
                continue;
            }
        }
    }
    return output;
}

bool FileReader::validateMovieValues(const string& name, const string& studio, int year, MovieRating rating, int length)
{
    bool output = true;

    if (name.empty() || studio.empty())
    {
        output = false;
    }

    if (rating == MovieRating::NOT_RATED)
    {
        output = false;
    }

    if (length < 0 || year < 1888)
    {
        output = false;
    }

    return output;
}

FileReader::~FileReader()
{
    //dtor
}

}
