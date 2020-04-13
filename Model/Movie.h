#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

#include "Enum/MovieRating.h"

namespace model
{
/*
* Handles implementation of the Movie class
*/
class Movie
{
public:
    /*
    * Constructs a new movie object
    *
    * @param name
    *       The name of the movie object
    * @param studio
    *       The studio name of the movie object
    * @param year
    *       The year of the movie object
    * @param rating
    *       The rating of the movie object
    * @param length
    *       The length of the movie object
    */
    Movie(const string& name, const string& studio, int year, MovieRating rating, int length);
    /*
    * Constructs a new movie object
    *
    *@param movie
            The movie object
    */
    Movie(Movie& movie);
    /*
    * Destructs the movie object
    */
    virtual ~Movie();

    /*
    * Returns the name of the movie
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->name
    */
    const string& getName() const;
    /*
    * Returns the studio of the movie
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->studio
    */
    const string& getStudio() const;
    /*
    * Returns the rating of the movie
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->rating
    */
    MovieRating getRating() const;
    /*
    * Returns the year of the movie
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->year
    */
    int getYear() const;
    /*
    * Returns the length of the movie
    *
    * @precondition none
    * @postcondition none
    *
    * @return this->length
    */
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
