#ifndef MOVIERATING_H
#define MOVIERATING_H

#include "Utils.h"

#include <string>
using namespace std;

/*
* Enum to store the available movie rating options
*/
enum MovieRating {G, PG, PG13, R, NOT_RATED};

/*
* Converts an integer to a MovieRating object
*
* @precondition none
* @postcondition none
*
* @param index
*       The index of the desired MovieRating object
*
* @return rating
*       The string representation of the rating index
*/
const string GET_RATING_STRING(int);

#endif // MOVIERATING_H
