#include "Movie.h"

namespace model
{
//
// TODO: Document this
//
Movie::Movie(const string& name, const string& studio, int year, Rating rating, int length)
{
    this->name = name;
    this->studio = studio;
    this->year = year;
    this->rating = rating;
    this->length = length;
}

const string& Movie::getName() const
{
    return this->name;
}

const string& Movie::getStudio() const
{
    return this->studio;
}

Movie::Rating Movie::getRating() const
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
