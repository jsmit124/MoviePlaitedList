#include "Movie.h"

namespace model
{

Movie::Movie(const string& name, const string& studio, int year, MovieRating rating, int length)
{
    this->name = name;
    this->studio = studio;
    this->year = year;
    this->rating = rating;
    this->length = length;
}

Movie::Movie(Movie& movie)
{
    this->name = movie.getName();
    this->studio = movie.getStudio();
    this->year = movie.getYear();
    this->rating = movie.getRating();
    this->length = movie.getLength();
}

const string& Movie::getName() const
{
    return this->name;
}

const string& Movie::getStudio() const
{
    return this->studio;
}

MovieRating Movie::getRating() const
{
    return this->rating;
}

int Movie::getYear() const
{
    return this->year;
}

int Movie::getLength() const
{
    return this->length;
}

Movie::~Movie()
{
    //dtor
}

}
