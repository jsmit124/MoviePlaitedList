#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

#include "MovieRating.h"

namespace model
{

class Movie
{
public:
    Movie(const string& name, const string& studio, int year, MovieRating rating, int length);
    Movie(Movie& movie);
    virtual ~Movie();

    const string& getName() const;
    const string& getStudio() const;
    MovieRating getRating() const;
    int getYear() const;
    int getLength() const;

private:
    string name;
    string studio;
    int year;
    MovieRating rating;
    int length;
};

}

#endif // MOVIE_H
